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
#include "vetkmeans.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <math.h>

#define UNKNOWN_FLOW_THRESH 1e9
#define PI 3.141592653576

typedef struct _OptFlowPyrLKResult
{
	std::vector<cv::Point2f> prev_points_;
	std::vector<cv::Point2f> next_points_;
	std::vector<uchar> state_;
	std::vector<float> err_;
}OptFlowPyrLKResult;

class VetOptFlowDetector: public VetDetectorStrategy
{
public:
	VetOptFlowDetector();
	~VetOptFlowDetector();

public:
	void detect(const cv::Mat &frame, std::vector<VetROI> &rois);
	void detect(cv::Mat &frame, std::vector<VetROI> &rois);
	bool optFlowFarneback(const cv::Mat &frame, cv::Mat &flow);

private:
	bool _optFlowPyrLK(const cv::Mat &frame, OptFlowPyrLKResult &result);
	void _createMask4Detection(const cv::Mat &frame);
	
	void _makeColorPalette();
	void _motion2color(cv::Mat &flow, cv::Mat &color);

	double _calcDistance(const cv::Point &a, const cv::Point &b);
	double _calcAngleInDegree(const cv::Point &a, const cv::Point &b);
	cv::Rect _findBoundingRect(const std::vector<cv::Point> &src);

private:
	// previous gray image
	cv::Mat prev_gray_img_;

	std::vector<cv::Point2f> prev_points_;

	// is ready for reading
	bool is_ready_;

	// pyrLK approach find maximum number of corners
	int pyrLK_max_corners_;

	// pyrLK approach pre-defined maximum number of clusters
	int pyrLK_max_clusters_;

	// pyrLK approach clusters overlap threshold
	double pyrLK_clusters_overlap_;

	// color palette for Optical Flow Farneback approach
	std::vector<cv::Scalar> color_palette_;

	// Mask for pyrLK detector
	cv::Mat _mask;
};

#endif 	// VETOPTFLOWDETECTOR_H