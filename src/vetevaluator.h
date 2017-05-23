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
* \file vetevaluator.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-05-10
*/

#ifndef VETEVALUATOR_H
#define VETEVALUATOR_H

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
#include <fstream>

#include <stdio.h>
#include <unistd.h>

#define SHOW_LABELED_VIDEO 	0
#define CAPSTONE_EVALUATOR	1

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
 * Some evaluator functions declared here
 */
void showLabeledVideo(std::string video_path, std::string labeled_file_path);
void capstoneEvaluator(std::string video_path, std::string labeled_file_path);

class VetEvaluator: public VetUserStrategy
{
public:
	VetEvaluator();
	~VetEvaluator();

public:
	void start(std::string video_path);

private:
	std::string labeled_file_path_;
};

#endif	// VETEVALUATOR_H