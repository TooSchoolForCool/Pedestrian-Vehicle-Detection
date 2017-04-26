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
	cv::Rect rect_;
	std::string label_;
	int ack_;
	int unack_;
	bool is_exist_;
}DetectedRegion;

class VetTracker
{
public:
	VetTracker(double threshold = 0.8);
	~VetTracker();

public:
	void update(std::vector<VetROI> &detected_res);
	void _getDetectedRegion(std::vector<VetROI> &detected_res);

private:
	double _calcOverlapped(const cv::Rect &a, const cv::Rect &b);
	void _updateDetectedRegion(DetectedRegion &dst, const VetROI &src);
	void _addDetectedRegion(const VetROI &src);
	void _clearNotExistRegion();

private:
	std::vector<DetectedRegion> detected_regions_;

	double overlap_threshold_;
};

#endif // VETTRACKER_H