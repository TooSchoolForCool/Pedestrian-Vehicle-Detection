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
* \file vethaardetector.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-18
*/

#include "vethaardetector.h"

#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

VetHaarDetector::VetHaarDetector(int detector_id)
{
	switch(detector_id){
		case HAAR_FRONT_CAR_DETECTOR:
			cout << "VetHaarDetector::VetHaarDetector: load " << HAAR_CASCADE_FRONT_CAR_XML << endl;
			cascade_.load(HAAR_CASCADE_FRONT_CAR_XML);
			break;
		default:
			cout << "VetHaarDetector::VetHaarDetector: No such option" << endl;
			break;
	}

	this->scaler_ = 1.1;
	this->min_neighbors_ = 3;
	this->haar_flags_ = 0 | CASCADE_SCALE_IMAGE;
	this->window_size_ = Size(30, 30);

	// cout << this->scaler_ << endl;
	// cout << this->min_neighbors_ << endl;
	// cout << this->haar_flags_ << endl;
	// cout << this->window_size_ << endl;
}

VetHaarDetector::~VetHaarDetector()
{
	cout << "VetHaarDetector::~VetHaarDetector: delete cascade_" << endl;
}

int VetHaarDetector::detect(const Mat &frame, vector<Rect> &rois)
{
	cout << "VetHaarDetector::detect: detect" << endl;

	// cout << this->scaler_ << endl;
	// cout << this->min_neighbors_ << endl;
	// cout << this->haar_flags_ << endl;
	// cout << this->window_size_ << endl;

	cascade_.detectMultiScale(frame, rois, scaler_, min_neighbors_, haar_flags_, window_size_);

	return 0;
}