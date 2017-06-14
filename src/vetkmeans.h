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
	// 修改版kmeans算法 KmaxMeans
	void kmeans(const vetPoints &points, std::vector<vetPoints> &clusters,
		unsigned int k, double overlap);

private:
	// kmeans算法实现
	void _kmeans(const vetPoints &points, std::vector<int> &clusters_index, unsigned int k);

	// 计算两点之间的距离
	double _calcDistance(const cv::Point &a, const cv::Point &b);

	// 更新聚类结果，若聚类的簇没有变化，则返回false
	bool _updateClustersIndex(const vetPoints &points, std::vector<int> &clusters_index,
		const std::vector<cv::Point> &clusters_means);

	// 计算每个簇的新的中心点
	void _updateClustersMeans(const vetPoints &points, const std::vector<int> &clusters_index,
		std::vector<cv::Point> &clusters_means);

	// 确定点a属于哪个簇，返回该簇的索引号
	int _findClosestCluster(const cv::Point &a, const std::vector<cv::Point> &clusters_means);

	// 判断聚类结果中簇和簇之间重叠的比例是否超过了预设定的阈值
	bool _isMerged(const vetPoints &points, const std::vector<int> &clusters_index,
		unsigned int k, double overlap);

	// 找到每个簇的最大外接矩形
	void _findClustersBoundingBox(const vetPoints &points, const std::vector<int> &clusters_index,
		std::vector<cv::Rect> &clusters_bounding_box, unsigned int k);
};

#endif 	// _VETKMEANS_H