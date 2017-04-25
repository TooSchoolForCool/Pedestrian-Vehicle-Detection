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

	// for cascade_ classifier
	double cascade_scaler_;
	int min_neighbors_;
	int haar_flags_;
	cv::Size window_size_;

	// for hog svm classifier
	double hit_threshold_;
	cv::Size win_stride_;
	cv::Size padding_;
	double hog_scaler_;
	int group_threshold_;

	std::string label_;
};

#endif	// VETCASCADEDETECTOR_H