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
* \file vetfastvideocapture.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#ifndef VETFASTVIDEOCAPTURE_H	// VETFASTVIDEOCAPTURE_H
#define VETFASTVIDEOCAPTURE_H	// VETFASTVIDEOCAPTURE_H

#include "vetconcurrentqueue.h"

#include <opencv2/opencv.hpp>

#include <iostream>

#include <pthread.h>

class VetFastVideoCapture
{
public:
	VetFastVideoCapture(std::string video_path, int queue_max_size);
	~VetFastVideoCapture();

public:
	void start();
	void stop();
	bool read(Mat &frame);

private:
	void update();

private:
	int queue_max_size_;
	bool stopped_;
	cv::VideoCapture video_stream_;
	VetConcurrentQueue<Mat> queue_;
};

#endif	// VETFASTVIDEOCAPTURE_H