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
* \file vetoptflowdetector.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-03-24
*/

#ifndef VETOPTFLOWDETECTOR_H
#define VETOPTFLOWDETECTOR_H

#include "vetdetectorstrategy.h"

#include <opencv2/opencv.hpp>

#include <iostream>

#define UNKNOWN_FLOW_THRESH 1e9 

class VetOptFlowDetector: public VetDetectorStrategy
{
public:
	VetOptFlowDetector();
	~VetOptFlowDetector();

public:
	void detect(const cv::Mat &frame, std::vector<VetROI> &rois);
	bool startFarneback(const cv::Mat &frame, cv::Mat &flow);

private:
	void _makeColorPalette();
	void motion2color(cv::Mat &flow, cv::Mat &color);

private:
	// previous gray image
	cv::Mat prev_gray_img_;

	// is ready for reading
	bool is_ready_;

	// color palette for Optical Flow Farneback approach
	std::vector<cv::Scalar> color_palette_;
};

#endif 	// VETOPTFLOWDETECTOR_H