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
#include "globals.h"

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