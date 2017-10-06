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
* \file vetcascadedetector.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-04-25
*/

#include "vetcascadedetector.h"

using namespace std;
using namespace cv;

VetCascadeDetector::VetCascadeDetector(DetectedObject detected_object)
{
	switch(detected_object)
	{
		case FULLBODY:
			cout << "[VetCascadeDetector::VetCascadeDetector]: load FULLBODY xml file" << HAAR_CASCADE_FULLBODY_XML << endl;

			cv_cascade_.load(HAAR_CASCADE_FULLBODY_XML);
			cascade_scaler_ = 1.1;
			min_neighbors_ = 3;
			haar_flags_ = 0 | CASCADE_SCALE_IMAGE;
			window_size_ = Size(52, 148);		// minimum window size

			cout << "[VetCascadeDetector::VetCascadeDetector]: load HOGDescriptor::getDefaultPeopleDetector()" << endl;
			cv_hog_detector_.setSVMDetector( HOGDescriptor::getDefaultPeopleDetector() );			
			hit_threshold_ = 0.3;
			win_stride_ = Size(8, 8);
			hog_padding_ = Size(16, 16);
			hog_scaler_ = 1.1;
			group_threshold_ = 2;

			padding_ = Size(16, 32);
			label_ = "People";
			break;
		default:
			cout << "VetCascadeDetector::VetCascadeDetector]: No such option" << endl;
			break;
	}
}

VetCascadeDetector::~VetCascadeDetector()
{
	cout << "[VetCascadeDetector::VetCascadeDetector]: delete VetCascadeDetector" << endl;
}

void VetCascadeDetector::detect(const Mat &frame, vector<VetROI> &rois)
{
	vector<Rect> cv_cascade_rects, cv_hog_rects;

	// clear previous rois recordsmake 
	rois.clear();

	cv_cascade_.detectMultiScale(frame, cv_cascade_rects, cascade_scaler_, min_neighbors_, haar_flags_, window_size_);

	// second cascaded detector -- hog svm detector
	for(vector<Rect>::iterator iter = cv_cascade_rects.begin(); iter != cv_cascade_rects.end(); iter++)
	{
		int tl_x = max(0, iter->tl().x - padding_.width);
		int tl_y = max(0, iter->tl().y - padding_.height);
		int width = iter->width + padding_.width * 2;
		int height = iter->height + padding_.height * 2;

		// check if roi region out of the frame boundary
		if(tl_x + width > frame.size().width)
			width = frame.size().width - tl_x;
		if(tl_y + height > frame.size().height)
			height = frame.size().height - tl_y;

		// create roi region in Rectangle
		Rect rect_roi(tl_x, tl_y, width, height);

		// create roi image
		Mat image_roi = frame(rect_roi);

		cv_hog_detector_.detectMultiScale(image_roi, cv_hog_rects, hit_threshold_, 
			win_stride_, hog_padding_, hog_scaler_, group_threshold_);

		if( !cv_hog_rects.empty() )
		{
			rois.push_back( VetROI(*iter, label_) );
		}
	}
}