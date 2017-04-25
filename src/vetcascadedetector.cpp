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
			padding_ = Size(32, 32);
			hog_scaler_ = 1.1;
			group_threshold_ = 2;

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
	vector<Rect> rects;

	// clear previous rois recordsmake 
	rois.clear();

	cv_cascade_.detectMultiScale(frame, rects, cascade_scaler_, min_neighbors_, haar_flags_, window_size_);

	// cv_hog_detector_.detectMultiScale(frame, rects, hit_threshold_, 
	// 	win_stride_, padding_, hog_scaler_, group_threshold_);

	for(vector<Rect>::iterator iter = rects.begin(); iter != rects.end(); iter++)
	{
		rois.push_back( VetROI(*iter, label_) );
	}
}