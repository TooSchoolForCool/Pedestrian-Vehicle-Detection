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
* \file vetcolordetector.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#include "vetcolordetector.h"

#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

VetColorDetector::VetColorDetector(int specification_id)
{
	switch(specification_id)
	{
		case RED_REGION:
			cout << "VetColorDetector::VetColorDetector: RED_REGION" << endl;

			sensitivity_ = 15;
			lower_bound_ = Scalar(0 - sensitivity_, 100, 50);
			upper_bound_ = Scalar(0 + sensitivity_, 255, 255);

			color_label_ = "Red";

			color_space_converter_ = COLOR_BGR2HSV;
			break;
		default:
			cout << "No such option..." << endl;
			break;
	}
}

VetColorDetector::~VetColorDetector()
{
	// ...
}

void VetColorDetector::detect(const Mat &frame, vector<VetROI> &rois)
{
	Mat hsvFrame;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	rois.clear();

	cvtColor(frame, hsvFrame, color_space_converter_);
	inRange(hsvFrame, lower_bound_, upper_bound_, hsvFrame);

	Mat element = getStructuringElement(MORPH_RECT, Size(25, 25));
	dilate(hsvFrame, hsvFrame, element);
	dilate(hsvFrame, hsvFrame, element);
	
	GaussianBlur(hsvFrame, hsvFrame, Size(5, 5), 0, 0);

	findContours(hsvFrame, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

	for(vector<vector<Point> >::iterator iter = contours.begin(); 
		iter != contours.end(); iter++){
		// rois.push_back(minAreaRect(*iter));
		rois.push_back( VetROI(boundingRect(*iter), color_label_) );
	}
}