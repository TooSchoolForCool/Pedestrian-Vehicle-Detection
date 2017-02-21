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
* \file vetdetectorcontext.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-18
*/

#include "vetdetectorcontext.h"
#include "vetdetectorstrategy.h"
#include "vethaardetector.h"

#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

/*!
 * \brief VetDetectorContext::VetDetectorContext 构造函数
 * \param detector_id 具体策略类别
 */
VetDetectorContext::VetDetectorContext(int detector_id)
{
	switch(detector_id){
		case HAAR_FRONT_CAR_DETECTOR:
			cout << "VetDetectorContext::VetDetectorContext: HAAR_FRONT_CAR_DETECTOR" << endl;
			ptr_detector_strategy_ = new VetHaarDetector(HAAR_FRONT_CAR_DETECTOR);
			break;
		default:
			cout << "no such option" << endl;
			break;
	}
}

/*!
 * \brief VetLaneContext::~VetLaneContext 析构函数
 */
VetDetectorContext::~VetDetectorContext()
{
    delete ptr_detector_strategy_;
}

int VetDetectorContext::detect(const Mat &frame, vector<Rect> &rois)
{
	ptr_detector_strategy_->detect(frame, rois);

	return 0;
}

void foo()
{
	cout << "Hello world..." << endl;
}