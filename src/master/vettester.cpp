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

#include <cstdio>
#include <unistd.h>

using namespace std;
using namespace cv;

static void (*ptr_test_process[])(string) 
	= {	frontRearCarHaarTester,				// FRONT_REAR_CAR_HAAR_TESTER
	   	NMSTester,							// NMS_TESTER
	   	videoPlayerTester,					// VIDEO_PLAYER_TESTER
	   	fasterVideoPlayerTester };			// FASTER_VIDEO_PLAYER_TESTER

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

void *thread1(void *ptr)
{
	int max_size = 10;
	int cnt = 100;

	// printf("start thread 1\n");
	while(cnt){
		if(q.size() != max_size){
			q.push(cnt);
			// printf("push:\t%5d, size:\t%d\n", cnt, q.size());
			cnt--;
		}
		//usleep(10);
	}
	
	return NULL;
}

void *thread2(void *ptr)
{
	int max_size = 10;
	int cnt = 100;
	int i;

	// printf("start thread 2\n");

	while(cnt){
		if( !q.empty() ){
			i = q.front();
			q.pop();
			// printf("pop:\t%5d, size:\t%d\n", i, q.size());
			cnt--;
			if(i == 0){
				printf("ERROR~~~~~~~~~~~~~~~\n");
				return NULL;
			}
		}
		//usleep(10);
	}
	
	return NULL;
}

void fasterVideoPlayerTester(string video_path)
{
	pthread_t id1, id2;
	int ret;

	// printf("create thread 1\n");
	ret = pthread_create(&id1, NULL, &thread1, NULL);
	// printf("create thread 1 is done\n");

	if(ret != 0){
		printf ("Create pthread error!\n");
		return;
	}

	// printf("create thread 2\n");
	ret = pthread_create(&id2, NULL, &thread2, NULL);
	// printf("create thread 2 is done\n");

	if(ret != 0){
		printf ("Create pthread error!\n");
		return;
	}


	pthread_join(id1, NULL);
	// printf("join thread 1 is done\n");	

	pthread_join(id2, NULL);
	// printf("join thread 2 is done\n");
	cout << "succeed" << endl;
}

void videoPlayerTester(string video_path)
{
	VideoCapture videoStream(video_path);
	Mat frame;

	while(videoStream.read(frame)){
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

void NMSTester(string image_path)
{
	VetImageProcessor image_processor;

	Mat image = imread(image_path);
	Mat originImg = image.clone();

	vector<Rect> rois;

	// Rect(x, y, width, height)
	rois.push_back( Rect(84, 48, 212 - 84, 176 - 48) );
	rois.push_back( Rect(12, 30, 76 - 12, 94 - 30) );
	rois.push_back( Rect(72, 36, 200 - 72, 164 - 36) );
	rois.push_back( Rect(12, 36, 76 - 12, 100 - 36) );

	image_processor.drawRectangles(originImg, rois, COLOR_GREEN);
	imshow("origin", originImg);

	image_processor.NMS(rois, 0.3);
	image_processor.drawRectangles(image, rois, COLOR_GREEN);
	imshow("After NMS", image);

	while(waitKey(30) != KEY_ESC)
		continue;
}

void frontRearCarHaarTester(string video_path)
{
	VideoCapture videoStream(video_path);
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

		image_processor.NMS(rois, 0.3);
		image_processor.drawRectangles(frame, rois, COLOR_RED);
		rois.clear();  

		imshow("frame", frame);

		char resp = waitKey(5);

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
