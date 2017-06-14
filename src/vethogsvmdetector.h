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

	// for opencv hog svm classifier
	// 特征向量和SVM划分超平面的距离，大于这个值的才作为目标返回
	double hit_threshold_;
	// 滑动窗口移动步长
	cv::Size win_stride_;
	// 检测窗口边缘扩展大小
	cv::Size padding_;
	// 图片每次缩小尺度
	double scaler_;
	// bounding box优化参数
	int group_threshold_;

	std::string label_;
};

#endif