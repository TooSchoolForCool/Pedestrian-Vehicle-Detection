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
* \file vetcascadedetector.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-04-25
*/

#ifndef VETCASCADEDETECTOR_H
#define VETCASCADEDETECTOR_H

#include "vetdetectorstrategy.h"

#include <opencv2/opencv.hpp>

#include <iostream>

class VetCascadeDetector: public VetDetectorStrategy
{
public:
	VetCascadeDetector(DetectedObject detected_object);
	~VetCascadeDetector();

public:
	void detect(const cv::Mat &frame, std::vector<VetROI> &rois);

private:
	cv::CascadeClassifier cv_cascade_;
	cv::HOGDescriptor cv_hog_detector_;

	// for opencv cascade_ classifier
	// 每次降采样缩放尺度
	double cascade_scaler_;
	// 每一个级联矩形应该保留的邻近个数
	int min_neighbors_;
	int haar_flags_;
	// 检测窗口大小
	cv::Size window_size_;

	// for opencv hog svm classifier
	// 特征向量和SVM划分超平面的距离，大于这个值的才作为目标返回
	double hit_threshold_;
	// 滑动窗口移动步长
	cv::Size win_stride_;
	// 检测窗口边缘扩展大小
	cv::Size hog_padding_;
	// 图片每次缩小尺度
	double hog_scaler_;
	// bounding box优化参数
	int group_threshold_;

	// for the whole detector
	cv::Size padding_;
	std::string label_;
};

#endif	// VETCASCADEDETECTOR_H