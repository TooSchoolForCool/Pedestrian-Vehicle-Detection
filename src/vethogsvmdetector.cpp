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
* \file vethogsvmdetector.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#include "vethogsvmdetector.h"

using namespace std;
using namespace cv;

VetHOGSVMDetector::VetHOGSVMDetector(int specification_id)
{
	switch(specification_id)
	{
		case FULLBODY:
			cout << "VetHOGSVMDetector::VetHOGSVMDetector: load HOGDescriptor::getDefaultPeopleDetector()" << endl;

			cv_hog_detector_.setSVMDetector( HOGDescriptor::getDefaultPeopleDetector() );
			
			hit_threshold_ = 0.3;
			win_stride_ = Size(8, 8);
			padding_ = Size(32, 32);
			scaler_ = 1.3;
			group_threshold_ = 2;

			label_ = "People";
			break;
		default:
			cout << "VetHOGSVMDetector::VetHOGSVMDetector: No such option" << endl;
			break;
	}
}

VetHOGSVMDetector::~VetHOGSVMDetector()
{
	cout << "VetHOGSVMDetector::~VetHOGSVMDetector: delete cv_hog_detector_" << endl;
}

void VetHOGSVMDetector::detect(const Mat &frame, vector<VetROI> &rois)
{
	vector<Rect> rects;

	cv_hog_detector_.detectMultiScale(frame, rects, hit_threshold_, 
		win_stride_, padding_, scaler_, group_threshold_);

	for(vector<Rect>::iterator iter = rects.begin(); iter != rects.end(); iter++)
	{
		rois.push_back( VetROI(*iter, label_) );
	}
}