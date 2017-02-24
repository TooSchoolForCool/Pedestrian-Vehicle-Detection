/**
* [
*  Copyright (c) 2016 by Vehicle-Eye Technology
*  ALL RIGHTS RESERVED.
*
*  The software and information contained herein are proprietary to,  and comprise
*  valuable trade secrets of, Vehicle-Eye Technology.  Disclosure of the software
*  and information will materially harm the business of Vehicle-Eye Technology.
*  This software is furnished pursuant to a written development agreement and may
*  be used, copied, transmitted, and stored only in accordance with the terms of
*  such agreement and with the inclusion of the above copyright notice.  This
*  software and information or any other copies thereof may not be provided or
*  otherwise made available to any other party.
* ]
*/


/*!
* \file vetimageprocessor.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#include "vetimageprocessor.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <algorithm>

using namespace std;
using namespace cv;

bool compareCvRect(Rect &a, Rect &b)
{
	// int a_y2 = a.br().y;
	// int b_y2 = b.br().y;

	// return a_y2 < b_y2;

	return a.area() > b.area();
}

VetImageProcessor::VetImageProcessor()
{
	// ...
}

VetImageProcessor::~VetImageProcessor()
{
	// ...
}

void VetImageProcessor::drawRectangles(Mat &frame, const vector<Rect> &rois,
	const Scalar &color, string label)
{
	if( !rois.empty() ){
		vector<Rect>::const_iterator roi = rois.begin();
		vector<Rect>::const_iterator end = rois.end();

		while(roi != end){
			rectangle(frame, *roi, color, 2);

			if(label != ""){
				putText(frame, label, roi->tl(), FONT_HERSHEY_TRIPLEX , 1.3, color); 
			}

			roi++;
		}
	}
}

void VetImageProcessor::NMS(vector<Rect> &rois, double overlap_threshold)
{
	if( rois.empty() )
		return;

	// initilize picked-up region vector, where we store the NMS result
	vector<Rect> pick;

	// sort the bounding boxes by the bottom-right 
	// y-coordinate of the bounding box
	sort(rois.begin(), rois.end(), compareCvRect);

	while( !rois.empty() ){
		// At the begining of each iteration, choose the last
		// bounding box as the picked-up region and push it into 
		// the pick vector. Then erase the picked-up last one in 
		// the rois vector.
		Rect cur_rect = rois[rois.size() - 1];
		pick.push_back(cur_rect);
		rois.erase(rois.end() - 1);

		vector<Rect>::iterator iter = rois.begin();
		while(iter != rois.end()){
			// find the overlap bounding box top-left & bottom-right coordinates
			int overlap_x1 = max(cur_rect.tl().x, iter->tl().x);
			int overlap_y1 = max(cur_rect.tl().y, iter->tl().y);
			int overlap_x2 = min(cur_rect.br().x, iter->br().x);
			int overlap_y2 = min(cur_rect.br().y, iter->br().y);

			// compute the width and height of the overlap between
			// computed bounding box(cur_rect) and the bounding box(iter)
			int overlap_width = max(0, overlap_x2 - overlap_x1 + 1);
			int overlap_height = max(0, overlap_y2 - overlap_y1 + 1);

			// compute the ratio of overlap between the computed
			// bounding box(cur_rect) and the bounding box(iter) in the rois
			double overlap_area = (float)(overlap_width * overlap_height);
			double overlap_rate = max(overlap_area / cur_rect.area(), overlap_area / iter->area());
			
			// if there is sufficient overlap, suppress the
			// current bounding box(iter)
			if(overlap_rate > overlap_threshold)
				iter = rois.erase(iter);
			else
				iter++;
		}
	}

	// update the region of interests
	rois.swap(pick);
}