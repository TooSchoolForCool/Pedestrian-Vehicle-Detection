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
* \file main.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#include "vethaardetector.h"
#include "vetroi.h"
#include "globals.h"
#include "vetutils.h"
#include "vettracker.h"

#include <opencv2/opencv.hpp>

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace cv;
using namespace std;


static char VIDEO_PATHS[10][1024] = {
	"../../data/video/HPIM0026.mov",
	"../../data/video/HPIM0031.mov",
	"../../data/video/HPIM0032.mov",
	"../../data/video/HPIM0085.mov",
	"../../data/video/HPIM0086.mov",
	"../../data/video/HPIM0095.mov",
	"../../data/video/HPIM0099.mov"
};

extern char VIDEO_PATH[1024] = "";
extern char OUTPUT_PATH[1024] = "./car_pos";
extern bool ENABLE_PEDESTRIAN = false;
extern bool ENABLE_VEHICLE = false;
extern bool ENABLE_OPTFLOW = false;
extern bool ENABLE_DEBUG = false;

int main(int argc, char **argv)
{	
	// parseArgs(argc, argv);

	VideoCapture video_stream;
	Mat frame;
	vector<int> compression_params;
	compression_params.push_back(IMWRITE_JPEG_QUALITY);
	compression_params.push_back(95);	

	VetDetectorStrategy *front_car_detector = new VetHaarDetector(FRONT_CAR);
	VetDetectorStrategy *rear_car_detector = new VetHaarDetector(REAR_CAR);
	VetTracker tracker(0.8, 2, 1, 2);
	vector<VetROI> result, tmp_res;

	int frame_cnt = 0;
	int sample_cnt = 1;
	char out_path[1024];

	for(int i = 0; i < 7; i++)
	{
		video_stream.open(VIDEO_PATHS[i]);
		frame_cnt = 0;

		while( video_stream.read(frame) ){
			if(frame_cnt++ % 15 != 0)
				continue;

			front_car_detector->detect(frame, tmp_res);
			result.insert(result.end(), tmp_res.begin(), tmp_res.end());

			rear_car_detector->detect(frame, tmp_res);
			result.insert(result.end(), tmp_res.begin(), tmp_res.end());
			
			NMS(result, 0.3);
			tracker.update(result);

			for(unsigned int j = 0; j < result.size(); j++)
			{
				Mat image_roi = frame(result[j].rect());

				sprintf(out_path, "%s/%d.jpg", OUTPUT_PATH, sample_cnt++);
				printf("[%d %d]: %s\n", i, j, out_path);

				imwrite(out_path, image_roi, compression_params);
			}
			
			result.clear();
		}
	}

	video_stream.release();

	return 0;
}