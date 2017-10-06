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
	void kmeans(const vetPoints &points, std::vector<vetPoints> &clusters,
		unsigned int k, double overlap);

private:
	void _kmeans(const vetPoints &points, std::vector<int> &clusters_index, unsigned int k);

	double _calcDistance(const cv::Point &a, const cv::Point &b);

	bool _updateClustersIndex(const vetPoints &points, std::vector<int> &clusters_index,
		const std::vector<cv::Point> &clusters_means);

	void _updateClustersMeans(const vetPoints &points, const std::vector<int> &clusters_index,
		std::vector<cv::Point> &clusters_means);

	int _findClosestCluster(const cv::Point &a, const std::vector<cv::Point> &clusters_means);

	bool _isMerged(const vetPoints &points, const std::vector<int> &clusters_index,
		unsigned int k, double overlap);

	void _findClustersBoundingBox(const vetPoints &points, const std::vector<int> &clusters_index,
		std::vector<cv::Rect> &clusters_bounding_box, unsigned int k);
};

#endif 	// _VETKMEANS_H