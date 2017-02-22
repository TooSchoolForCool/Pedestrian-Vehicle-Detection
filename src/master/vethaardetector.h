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
* \file vethaardetector.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-18
*/

#ifndef VETHAARDETECTOR_H
#define VETHAARDETECTOR_H

#include "vetdetectorstrategy.h"

#include <opencv2/opencv.hpp>

#include <iostream>

class VetHaarDetector: public VetDetectorStrategy
{
public:
	VetHaarDetector(int detector_id);
	~VetHaarDetector();

public:
	void detect(const cv::Mat &frame, std::vector<cv::Rect> &rois);

private:
	cv::CascadeClassifier cascade_;
	double scaler_;
	int min_neighbors_;
	int haar_flags_;
	cv::Size window_size_;
};


#endif	// VETHAARDETECTOR_H