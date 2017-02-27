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
* \file vetcolordetector.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#ifndef VETCOLORDETECTOR_H
#define VETCOLORDETECTOR_H

#include "vetdetectorstrategy.h"

#include <opencv2/opencv.hpp>

#include <iostream>

class VetColorDetector: public VetDetectorStrategy
{
public:
	VetColorDetector(int specification_id);
	~VetColorDetector();

public:
	void detect(const cv::Mat &frame, std::vector<cv::Rect> &rois);

private:
	cv::Scalar lower_bound_;
	cv::Scalar upper_bound_;
	int sensitivity_;
};

#endif