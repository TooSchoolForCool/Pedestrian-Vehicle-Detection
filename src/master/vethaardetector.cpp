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

VetHaarDetector::VetHaarDetector(int specification_id)
{
	switch(specification_id){
		case FRONT_CAR:
			cout << "VetHaarDetector::VetHaarDetector: load FRONT_CAR xml file" << HAAR_CASCADE_FRONT_CAR_XML << endl;
			cascade_.load(HAAR_CASCADE_FRONT_CAR_XML);
			this->scaler_ = 1.1;
			this->min_neighbors_ = 3;
			this->haar_flags_ = 0 | CASCADE_SCALE_IMAGE;
			this->window_size_ = Size(120, 120);	// minimum window size
			this->label_ = "Car";
			break;
		case REAR_CAR:
			cout << "VetHaarDetector::VetHaarDetector: load REAR_CAR xml file" << HAAR_CASCADE_REAR_CAR_XML << endl;
			cascade_.load(HAAR_CASCADE_REAR_CAR_XML);
			this->scaler_ = 1.1;
			this->min_neighbors_ = 3;
			this->haar_flags_ = 0 | CASCADE_SCALE_IMAGE;
			this->window_size_ = Size(120, 120);	// minimum window size
			this->label_ = "Car";
			break;
		case FULLBODY:
			cout << "VetHaarDetector::VetHaarDetector: load FULLBODY xml file" << HAAR_CASCADE_FULLBODY_XML << endl;
			cascade_.load(HAAR_CASCADE_FULLBODY_XML);
			this->scaler_ = 1.1;
			this->min_neighbors_ = 3;
			this->haar_flags_ = 0 | CASCADE_SCALE_IMAGE;
			this->window_size_ = Size(52, 148);		// minimum window size
			this->label_ = "People";
			break;
		default:
			cout << "VetHaarDetector::VetHaarDetector: No such option" << endl;
			break;
	}

	// cout << this->scaler_ << endl;
	// cout << this->min_neighbors_ << endl;
	// cout << this->haar_flags_ << endl;
	// cout << this->window_size_ << endl;
}

VetHaarDetector::~VetHaarDetector()
{
	cout << "VetHaarDetector::~VetHaarDetector: delete cascade_" << endl;
}

void VetHaarDetector::detect(const Mat &frame, vector<VetROI> &rois)
{
	// cout << "VetHaarDetector::detect: detect" << endl;

	// cout << this->scaler_ << endl;
	// cout << this->min_neighbors_ << endl;
	// cout << this->haar_flags_ << endl;
	// cout << this->window_size_ << endl;
	vector<Rect> rects;

	// clear previous rois records
	rois.clear();

	cascade_.detectMultiScale(frame, rects, scaler_, min_neighbors_, haar_flags_, window_size_);

	for(vector<Rect>::iterator iter = rects.begin(); iter != rects.end(); iter++){
		rois.push_back( VetROI(*iter, label_) );
	}
}