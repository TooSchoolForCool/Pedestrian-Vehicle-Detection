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
* \file kmeans.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-04-21
*/

#ifndef _VETKMEANS_H
#define _VETKMEANS_H

#include "veterror.h"

#include <opencv2/opencv.hpp>

#include <iostream>

typedef std::vector<cv::Point> vetPoints;

class VetKmeans
{
public:
	VetKmeans();
	~VetKmeans();

public:
	void kmeans(const vetPoints &points, std::vector<vetPoints> &clusters, int k);

private:
	double _calcDistance(const cv::Point &a, const cv::Point &b);
};

#endif 	// _VETKMEANS_H