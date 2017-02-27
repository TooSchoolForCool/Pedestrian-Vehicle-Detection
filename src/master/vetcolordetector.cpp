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
#include "vetdetectorstrategy.h"

#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

VetColorDetector::VetColorDetector(int specification_id)
{
	switch(specification_id){
		case RED_REGION:
			sensitivity_ = 15;
			lower_bound_ = Scalar(0 - sensitivity_, 100, 100);
			upper_bound_ = Scalar(0 + sensitivity_, 255, 255);
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

void VetColorDetector::detect(const Mat &frame, vector<Rect> &rois)
{
	Mat hsvFrame;

	cvtColor(frame, hsvFrame, COLOR_BGR2HSV);

	imshow("HSV Channel", hsvFrame);
	
	while(waitKey(30) != 27)
		continue;

	destroyWindow("HSV Channel");
}