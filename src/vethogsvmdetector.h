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
* \file vethogsvmdetector.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/ 

#ifndef VETHOGSVMDETECTOR_H
#define VETHOGSVMDETECTOR_H

#include "vetdetectorstrategy.h"

#include <opencv2/opencv.hpp>

#include <iostream>

class VetHOGSVMDetector: public VetDetectorStrategy
{
public:
	VetHOGSVMDetector(DetectedObject detected_object);
	~VetHOGSVMDetector();

public:
	void detect(const cv::Mat &frame, std::vector<VetROI> &rois);

private:
	cv::HOGDescriptor cv_hog_detector_;

	double hit_threshold_;
	cv::Size win_stride_;
	cv::Size padding_;
	double scaler_;
	int group_threshold_;

	std::string label_;
};

#endif