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
* \file vettester.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/


#include "vettester.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <algorithm>

using namespace std;
using namespace cv;

static void (*ptr_test_process[])(void) 
	= {frontRearCarHaarTester,
	   NMSTester};

VetTester::VetTester(int tester_id)
{
	this->tester_id_ = tester_id;
}

VetTester::~VetTester()
{
	//nop
}

void VetTester::setTesterID(int tester_id)
{
	tester_id_ = tester_id;
}

void VetTester::run()
{
	ptr_test_process[tester_id_]();
}

void NMSTester()
{
	VetImageProcessor image_processor;
	image_processor.NMS();	
}

void frontRearCarHaarTester()
{
	VideoCapture videoStream(TEST_VIDEO_PATH);
	Mat frame;
	vector<Rect> temp_rois, rois;

	VetDetectorContext front_car_detector(HAAR_FRONT_CAR_DETECTOR);
	VetDetectorContext rear_car_detector(HAAR_REAR_CAR_DETECTOR);

	VetImageProcessor image_processor;

	while(videoStream.read(frame)){
		front_car_detector.detect(frame, temp_rois);
		rois.insert(rois.end(), temp_rois.begin(), temp_rois.end());

		rear_car_detector.detect(frame, temp_rois);
		rois.insert(rois.end(), temp_rois.begin(), temp_rois.end());

		image_processor.drawRectangles(frame, rois, COLOR_RED);
		image_processor.NMS(rois, 0.3);
		rois.clear();

		imshow("frame", frame);

		char resp = waitKey(30);

		if(resp == KEY_ESC){
			cout << "window: frame closed" << endl;
			break;
		}
		else if(resp == KEY_SPACE){
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}
}
