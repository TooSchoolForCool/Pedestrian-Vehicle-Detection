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
* \file vetimageprocessor.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#ifndef VETIMAGEPROCESSOR_H
#define VETIMAGEPROCESSOR_H

#include <opencv2/opencv.hpp>

#include <iostream>

#define COLOR_BLUE 	cv::Scalar(255, 0, 0)
#define COLOR_GREEN	cv::Scalar(0, 255, 0)
#define COLOR_RED 	cv::Scalar(0, 0, 255)

#define KEY_ESC		27
#define KEY_SPACE	32

class VetImageProcessor
{
public:
	VetImageProcessor();
	~VetImageProcessor();

public:
	void drawRectangles(cv::Mat &frame, const std::vector<cv::Rect> &rois,
		const cv::Scalar &color, std::string label="");

	void NMS(std::vector<cv::Rect> &rois, double overlap_threshold);

private:

};

#endif