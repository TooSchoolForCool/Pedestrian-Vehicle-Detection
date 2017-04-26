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
* \file vettracker.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-04-26
*/

#ifndef VETTRACKER_H
#define VETTRACKER_H

#include "vetroi.h"

#include <opencv2/opencv.hpp>

#include <iostream>

typedef struct _DetectedRegion
{
	VetROI detected_res_;
	int ack_,
	int unack_
}DetectedRegion;

class VetTracker()
{
public:
	VetTracker();
	~VetTracker();

public:
	update(const std::vector<VetROI> &detected_res);
	getDetectedRegion(std::vector<VetROI> &detected_res);

private:
	_calcOverlapped(cv::Rect &a, cv::Rect &b);

private:
	std::vector<DetectedRegion> detected_regions_;
};

#endif // VETTRACKER_H