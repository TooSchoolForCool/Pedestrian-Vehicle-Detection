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
* \file vetdetectorcontext.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-18
*/


#ifndef VETDETECTORCONTEXT_H
#define VETDETECTORCONTEXT_H

#include "vetdetectorstrategy.h"
#include "vethaardetector.h"

#include <opencv2/opencv.hpp>

#include <iostream>

/*!
 * \brief The VetDetectorContext class
 */
class VetDetectorContext
{
public:
	VetDetectorContext(int strategy_id);
	~VetDetectorContext();

public:
	void detect(const cv::Mat &frame, std::vector<cv::Rect> &rois);

private:
	VetDetectorStrategy *ptr_detector_strategy_;
};

#endif	// VETDETECTORCONTEXT_H