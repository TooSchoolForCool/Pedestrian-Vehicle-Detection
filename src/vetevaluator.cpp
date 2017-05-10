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
* \file vetevaluator.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-05-10
*/

#include "vetevaluator.h"

using namespace std;
using namespace cv;

static void (*ptr_test_process[])(string, string) 
	= {
		showLabeledVideo,	// SHOW_LABELED_VIDEO
		capstoneEvaluator 	// CAPSTONE_EVALUATOR
	  };

VetEvaluator::VetEvaluator()
{
	cout << "[VetEvaluator::VetEvaluator]: VetEvaluator created" << endl;

	labeled_file_path_ = "HPIM0026_Trimed_vehicle_1-219.txt";
}

VetEvaluator::~VetEvaluator()
{
	cout << "[VetEvaluator::~VetEvaluator]: VetEvaluator deleted" << endl;
}

void VetEvaluator::start(string video_path)
{
	cout << "[VetEvaluator::start]: test mode starts" << endl;

	ptr_test_process[CAPSTONE_EVALUATOR](video_path, labeled_file_path_);

	cout << "[VetEvaluator::start]: test mode ends" << endl;
}

void showLabeledVideo(string video_path, string labeled_file_path)
{
	printf("[SHOW_LABELED_VIDEO] starts\n");

	ifstream file_in(labeled_file_path.c_str());

	if( !file_in.is_open() )
	{
		string str = "Cannot open file " + labeled_file_path;
		error(str);
	}

	VetFastVideoCapture fvs(video_path, 128);

	if( !fvs.isOpened() )
		error(string("Cannot open video:") + video_path);

	int cur_frame_num, obj_num, x, y, width, height;
	string label;
	vector<VetROI> targets;
	Mat frame;

	fvs.start();

	while( fvs.more() )
	{
		if ( fvs.read(frame) )
		{
			file_in >> cur_frame_num >> obj_num;

			for(int i = 0; i < obj_num; i++)
			{
				file_in >> cur_frame_num >> x >> y >> width >> height >> label;
				
				Rect rect(x, y, width, height);

				targets.push_back( VetROI(rect, "car") );
			}

			drawRectangles(frame, targets, COLOR_BLUE);
			targets.clear();
			
			imshow("frame", frame);

			if(cur_frame_num == 218)
				break;
		}

		char resp = waitKey(30);

		if(resp == KEY_ESC)
		{
			cout << "window: frame closed" << endl;
			destroyWindow("frame");
			break;
		}
		else if(resp == KEY_SPACE)
		{
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	fvs.stop();
	file_in.close();

	printf("[SHOW_LABELED_VIDEO] ends.\n");
}

void capstoneEvaluator(string video_path, string labeled_file_path)
{
	printf("[CAPSTONE_EVALUATOR] starts.\n");

	VetDetectorFactory detector_factory;
	VetFastVideoCapture fvs(video_path, 128);

	VetOptFlowDetector optFlowDetector;
	VetDetectorStrategy *human_detector = detector_factory.createDetector(CASCADE_DETECTOR, FULLBODY);
	VetDetectorStrategy *front_car_detector = detector_factory.createDetector(HAAR_DETECTOR, FRONT_CAR);
	VetDetectorStrategy *rear_car_detector = detector_factory.createDetector(HAAR_DETECTOR, REAR_CAR);

	VetTracker human_tracker(0.8, 2, 1, 2);
	VetTracker car_tracker(0.8, 2, 1, 2);

	Mat frame;
	vector<VetROI> rois_car, rois_opt, rois_human, temp_rois;

	int cur_frame_num, obj_num, x, y, width, height;
	string label;
	vector<VetROI> targets;

	ifstream file_in(labeled_file_path.c_str());

	if( !file_in.is_open() )
	{
		string str = "Cannot open file " + labeled_file_path;
		error(str);
	}
	
	int cnt = 0;

	if( !fvs.isOpened() )
		error(string("Cannot open video:") + video_path);

	fvs.start();

	namedWindow("frame");
	moveWindow("frame", 25, 25);

	// VideoWriter writer("VideoTest.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0, Size(1280, 720));

	while( fvs.more() )
	{
		if ( fvs.read(frame) )
		{
			// if(cnt++ % 2 == 1)
			// 	continue;
			
			front_car_detector->detect(frame, temp_rois);
			rois_car.insert(rois_car.end(), temp_rois.begin(), temp_rois.end());

			rear_car_detector->detect(frame, temp_rois);
			rois_car.insert(rois_car.end(), temp_rois.begin(), temp_rois.end());

			human_detector->detect(frame, rois_human);

			optFlowDetector.detect(frame, rois_opt);

			NMS(rois_car, 0.3);
			NMS(rois_human, 0.3);

			human_tracker.update(rois_human);
			car_tracker.update(rois_car);

			drawRectangles(frame, rois_opt, COLOR_RED);
			drawRectangles(frame, rois_car, COLOR_GREEN);
			drawRectangles(frame, rois_human, COLOR_BLUE);
			
			rois_opt.clear();
			rois_car.clear();
			rois_human.clear();

			file_in >> cur_frame_num >> obj_num;

			for(int i = 0; i < obj_num; i++)
			{
				file_in >> cur_frame_num >> x >> y >> width >> height >> label;
				
				Rect rect(x, y, width, height);

				targets.push_back( VetROI(rect, "car") );
			}

			drawRectangles(frame, targets, COLOR_BLUE);
			targets.clear();
			
			// writer << frame;
			imshow("frame", frame);
		}

		char resp = waitKey(30);

		if(resp == KEY_ESC)
		{
			cout << "window: frame closed" << endl;
			destroyWindow("frame");
			break;
		}
		else if(resp == KEY_SPACE)
		{
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	fvs.stop();

	delete human_detector;
	delete rear_car_detector;
	delete front_car_detector;

	printf("[CAPSTONE_EVALUATOR] ends.\n");
}