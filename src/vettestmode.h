#ifndef VETTESTMODE_H
#define VETTESTMODE_H

#include "vetuserstrategy.h"
#include "vetdetectorstrategy.h"
#include "vethaardetector.h"
#include "vetcolordetector.h"
#include "vetoptflowdetector.h"
#include "vettracker.h"
#include "vetutils.h"
#include "vetconcurrentqueue.h"
#include "vetfastvideocapture.h"
#include "vetroi.h"
#include "veterror.h"

#include <opencv2/opencv.hpp>

#include <iostream>

#include <stdio.h>
#include <unistd.h>

#define CAR_HAAR_TESTER 			0
#define NMS_TESTER 					1
#define VIDEO_PLAYER_TESTER 		2
#define FAST_VIDEO_PLAYER_TESTER	3
#define FAST_CAR_HAAR_TESTER		4
#define FAST_FULLBODY_HAAR_TESTER	5
#define RED_DETECTOR_TESTER			6
#define FAST_HOG_SVM_TESTER			7
#define OPT_FLOW_TESTER				8
#define CASCADE_HUMAN_TESTER		9
#define TRACKER_TESTER				10
#define CAPSTONE_TESTER				11
#define FOO_TESTER					12

/**
 * Tester Video File Path
 */
#define TEST_VIDEO_PATH "../data/video/HPIM0026.mov"
#define TEST_VIDEO_PATH_2 "../data/video/HPIM0096.mov"
#define TEST_TRIMED_VIDEO_PATH "../data/video/HPIM0026_Trimed.mov"
#define TEST_PEOPLE_VIDEO_PATH "../data/video/HPIM0026_people.mp4"

/**
 * Tester Picture File Path
 */
#define PIC_NMS_PATH "../data/images/nms.jpg"
#define PIC_RED_REGION_TEST_PATH "../data/images/red_region_test.jpg"

/**
 * Tester Functions
 */
void carHaarTester(std::string video_path);
void NMSTester(std::string image_path);
void videoPlayerTester(std::string video_path);
void fastVideoPlayerTester(std::string video_path);
void fastCarHaarTester(std::string video_path);
void fastFullbodyHaarTester(std::string video_path);
void redDetectorTester(std::string video_path);
void fastHOGSVMTester(std::string video_path);
void optFlowTester(std::string video_path);
void cascadeHumanTester(std::string video_path);
void trackerTester(std::string video_path);
void capstoneTester(std::string video_path);
void fooTester(std::string video_path);

class VetTestMode: public VetUserStrategy
{
public:
	VetTestMode();
	~VetTestMode();

private:
	void start(std::string path);
};

#endif