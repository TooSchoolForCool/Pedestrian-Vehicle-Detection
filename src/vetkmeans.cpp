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
* \file vetkmeans.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-04-21
*/

#include "vetkmeans.h"

VetKmeans::VetKmeans()
{
	// ...
}

VetKmeans::~VetKmeans()
{
	// ...
}

void VetKmeans::kmeans(const vetPoints &points, std::vector<vetPoints> &clusters, int k)
{
	clusters.clear();

	if(k <= 0)
	{
		error("[VetKmeans::kmeans] k should be a positive number");
	}

	if(k == 1)
	{
		clusters.push_back(points);
		return;
	}

	
}

double VetKmeans::_calcDistance(const cv::Point &a, const cv::Point &b)
{
	double distance;

    distance = powf((a.x - b.x), 2) + powf((a.y - b.y), 2);    
    distance = sqrtf(distance);    
    
    return distance;   
}