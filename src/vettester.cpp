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

#include <stdio.h>
#include <unistd.h>

using namespace std;
using namespace cv;

static void (*ptr_test_process[])(string) 
	= {	
		carHaarTester,						// CAR_HAAR_TESTER
	   	NMSTester,							// NMS_TESTER
	   	videoPlayerTester,					// VIDEO_PLAYER_TESTER
	   	fastVideoPlayerTester,				// FAST_VIDEO_PLAYER_TESTER
	   	fastCarHaarTester,					// FAST_CAR_HAAR_TESTER
	   	fastFullbodyHaarTester,				// FAST_FULLBODY_HAAR_TESTER
	   	redDetectorTester,					// RED_DETECTOR_TESTER
	   	fastHOGSVMTester					// FAST_HOG_SVM_TESTER
	  };			

static VetConcurrentQueue<int> q;

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

void VetTester::run(string file_path)
{

	ptr_test_process[tester_id_](file_path);
}

/*******************************************
 * Tester Functions go below
 *******************************************/

void fastVideoPlayerTester(string video_path)
{
	VetFastVideoCapture fvs(video_path, 128);
	Mat frame;

	printf("FAST_VIDEO_PLAYER_TESTER starts.\n");

	fvs.start();

	while( fvs.more() ){
		if( fvs.read(frame) ){
			imshow("frame", frame);
		}

		char resp = waitKey(30);

		if(resp == KEY_ESC){
			destroyWindow("frame");
			cout << "window: frame closed" << endl;
			break;
		}
		else if(resp == KEY_SPACE){
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	fvs.stop();

	printf("FAST_VIDEO_PLAYER_TESTER ends.\n");
}

void videoPlayerTester(string video_path)
{
	VideoCapture videoStream(video_path);
	Mat frame;

	printf("VIDEO_PLAYER_TESTER starts.\n");

	while(videoStream.read(frame)){
		imshow("frame", frame);

		char resp = waitKey(30);

		if(resp == KEY_ESC){
			destroyWindow("frame");
			cout << "window: frame closed" << endl;
			break;
		}
		else if(resp == KEY_SPACE){
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	printf("VIDEO_PLAYER_TESTER ends.\n");
}

void NMSTester(string image_path)
{
	Mat image = imread(image_path);
	Mat originImg = image.clone();

	vector<VetROI> rois;

	printf("NMS_TESTER starts.\n");

	// Rect(x, y, width, height)
	rois.push_back( Rect(84, 48, 212 - 84, 176 - 48) );
	rois.push_back( Rect(12, 30, 76 - 12, 94 - 30) );
	rois.push_back( Rect(72, 36, 200 - 72, 164 - 36) );
	rois.push_back( Rect(12, 36, 76 - 12, 100 - 36) );

	drawRectangles(originImg, rois, COLOR_GREEN);
	imshow("origin", originImg);

	NMS(rois, 0.3);
	drawRectangles(image, rois, COLOR_GREEN);
	imshow("After NMS", image);

	while(waitKey(30) != KEY_ESC)
		continue;

	destroyWindow("origin");
	destroyWindow("After NMS");

	printf("NMS_TESTER ends.\n");
}

void carHaarTester(string video_path)
{
	VideoCapture videoStream(video_path);
	Mat frame;
	vector<VetROI> temp_rois, rois;

	VetDetectorContext front_car_detector(HAAR_DETECTOR, FRONT_CAR);
	VetDetectorContext rear_car_detector(HAAR_DETECTOR, REAR_CAR);

	printf("CAR_HAAR_TESTER starts.\n");

	while(videoStream.read(frame)){
		front_car_detector.detect(frame, temp_rois);
		rois.insert(rois.end(), temp_rois.begin(), temp_rois.end());

		rear_car_detector.detect(frame, temp_rois);
		rois.insert(rois.end(), temp_rois.begin(), temp_rois.end());

		NMS(rois, 0.3);
		drawRectangles(frame, rois, COLOR_RED, "Car");
		rois.clear();  

		imshow("frame", frame);

		char resp = waitKey(5);

		if(resp == KEY_ESC){
			cout << "window: frame closed" << endl;
			destroyWindow("frame");
			break;
		}
		else if(resp == KEY_SPACE){
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	videoStream.release();	

	printf("CAR_HAAR_TESTER ends.\n");
}

void fastCarHaarTester(string video_path)
{
	VetFastVideoCapture fvs(video_path, 128);
	Mat frame;
	vector<VetROI> temp_rois, rois;

	VetDetectorContext front_car_detector(HAAR_DETECTOR, FRONT_CAR);
	VetDetectorContext rear_car_detector(HAAR_DETECTOR, REAR_CAR);

	printf("FAST_CAR_HAAR_TESTER starts.\n");

	fvs.start();

	while( fvs.more() ){
		if ( fvs.read(frame) ){
			front_car_detector.detect(frame, temp_rois);
			rois.insert(rois.end(), temp_rois.begin(), temp_rois.end());

			rear_car_detector.detect(frame, temp_rois);
			rois.insert(rois.end(), temp_rois.begin(), temp_rois.end());

			NMS(rois, 0.3);
			drawRectangles(frame, rois, COLOR_RED, "Car");
			rois.clear();  

			imshow("frame", frame);
		}

		char resp = waitKey(5);

		if(resp == KEY_ESC){
			cout << "window: frame closed" << endl;
			destroyWindow("frame");
			break;
		}
		else if(resp == KEY_SPACE){
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	fvs.stop();
	printf("FAST_CAR_HAAR_TESTER ends.\n");
}

void fastFullbodyHaarTester(string video_path)
{
	VetFastVideoCapture fvs(video_path, 128);
	Mat frame;
	vector<VetROI> rois;

	VetDetectorContext human_detector(HAAR_DETECTOR, FULLBODY);

	printf("FAST_FULLBODY_HAAR_TESTER starts.\n");

	fvs.start();

	while( fvs.more() ){
		if ( fvs.read(frame) ){
			human_detector.detect(frame, rois);

			NMS(rois, 0.3);
			drawRectangles(frame, rois, COLOR_RED, "People");
			rois.clear();  

			imshow("frame", frame);
		}

		char resp = waitKey(5);

		if(resp == KEY_ESC){
			cout << "window: frame closed" << endl;
			destroyWindow("frame");
			break;
		}
		else if(resp == KEY_SPACE){
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	fvs.stop();
	printf("FAST_FULLBODY_HAAR_TESTER ends.\n");
}

void redDetectorTester(string video_path)
{
	VetFastVideoCapture fvs(video_path, 128);
	Mat frame;
	vector<VetROI> rois;

	VetDetectorContext color_detector(COLOR_DETECTOR, RED_REGION);

	printf("FAST_FULLBODY_HAAR_TESTER starts.\n");

	fvs.start();

	while( fvs.more() ){
		if ( fvs.read(frame) ){
			// Mat hsvImage;
			color_detector.detect(frame, rois);

			NMS(rois, 0.3);
			drawRectangles(frame, rois, COLOR_RED, "Red");
			rois.clear();  

			imshow("frame", frame);
		}

		char resp = waitKey(5);

		if(resp == KEY_ESC){
			cout << "window: frame closed" << endl;
			destroyWindow("frame");
			break;
		}
		else if(resp == KEY_SPACE){
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	fvs.stop();
	printf("FAST_FULLBODY_HAAR_TESTER ends.\n");
}

void fastHOGSVMTester(std::string video_path)
{
	VetFastVideoCapture fvs(video_path, 128);
	Mat frame;
	vector<VetROI> rois;

	VetDetectorContext human_detector(HOG_SVM_DETECTOR, FULLBODY);

	printf("FAST_HOG_SVM_TESTER starts.\n");

	fvs.start();

	while( fvs.more() ){
		if ( fvs.read(frame) ){
			human_detector.detect(frame, rois);

			NMS(rois, 0.3);
			drawRectangles(frame, rois, COLOR_RED, "People");
			rois.clear();  

			imshow("frame", frame);
		}

		char resp = waitKey(5);

		if(resp == KEY_ESC){
			cout << "window: frame closed" << endl;
			destroyWindow("frame");
			break;
		}
		else if(resp == KEY_SPACE){
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	fvs.stop();
	printf("FAST_HOG_SVM_TESTER ends.\n");
}
