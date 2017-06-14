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

using namespace std;
using namespace cv;

VetKmeans::VetKmeans()
{
	// ...
}

VetKmeans::~VetKmeans()
{
	// ...
}

// 修改版kmeans算法 KmaxMeans
void VetKmeans::kmeans(const vetPoints &points, vector<vetPoints> &clusters,
	unsigned int k, double overlap)
{
	vector<int> clusters_index(points.size(), -1);

	if(points.size() < k)
	{
		k = points.size();
	}

	while(k >= 1)
	{
		// 使用kmeans算法聚类
		_kmeans(points, clusters_index, k);

		// 判断是否需要重新聚类
		if( _isMerged(points, clusters_index, k, overlap) )
			k--;
		else
			break;
	}

	// initialize clusters vector
	clusters.clear();
	for(unsigned int i = 0; i < k; i++)
	{
		clusters.push_back( vector<Point>() );
	}

	// push every point into its clusters according to its index
	// 返回聚类结果
	for(unsigned int i = 0; i < points.size(); i++)
	{
		clusters[clusters_index[i]].push_back(points[i]);
	}
}

// kmeans算法实现
void VetKmeans::_kmeans(const vetPoints &points, vector<int> &clusters_index, unsigned int k)
{
	vector<Point> clusters_means(k);

	// Initialize middle point
	for(unsigned int i = 0; i < k; i++)
	{
		// points[i] belongs to cluster #i
		clusters_index[i] = i;
		// the middle point of cluster #i is points[i]
		clusters_means[i] = points[i];
	}

	// 更新每个簇的中心点
	while(_updateClustersIndex(points, clusters_index, clusters_means))
	{
		_updateClustersMeans(points, clusters_index, clusters_means);
	}
}

// 计算两点之间的距离
double VetKmeans::_calcDistance(const cv::Point &a, const cv::Point &b)
{
	double distance;

    distance = powf((a.x - b.x), 2) + powf((a.y - b.y), 2);    
    distance = sqrtf(distance);    
    
    return distance;   
}

// 更新聚类结果，若聚类的簇没有变化，则返回false
bool VetKmeans::_updateClustersIndex(const vetPoints &points, vector<int> &clusters_index,
	const vector<Point> &clusters_means)
{
	bool isChanged = false;

	for(unsigned int i = 0; i < clusters_index.size(); i++)
	{
		int closest_cluster_index = _findClosestCluster(points[i], clusters_means);

		if(clusters_index[i] != closest_cluster_index)
		{
			isChanged = true;
			clusters_index[i] = closest_cluster_index;
		}
	}

	return isChanged;
}

// 计算每个簇的新的中心点
void VetKmeans::_updateClustersMeans(const vetPoints &points, const vector<int> &clusters_index,
	vector<Point> &clusters_means)
{
	vector<int> clusters_cnt(clusters_means.size(), 0);

	for(unsigned int i = 0; i < clusters_means.size(); i++)
	{
		clusters_means[i] = Point(0, 0);
	}

	for(unsigned int i = 0; i < clusters_index.size(); i++)
	{
		clusters_means[clusters_index[i]].x += points[i].x;
		clusters_means[clusters_index[i]].y += points[i].y;

		clusters_cnt[clusters_index[i]]++;
	}

	for(unsigned int i = 0; i < clusters_means.size(); i++)
	{
		if(clusters_cnt[i] != 0)
		{
			clusters_means[i].x /= clusters_cnt[i];
			clusters_means[i].y /= clusters_cnt[i];
		}
	}
}

// 确定点a属于哪个簇，返回该簇的索引号
int VetKmeans::_findClosestCluster(const Point &a, const vector<Point> &clusters_means)
{
	double min_distance = _calcDistance(clusters_means[0], a);
	int index = 0;

	for(unsigned int i = 1; i < clusters_means.size(); i++)
	{
		double distance = _calcDistance(clusters_means[i], a);

		if(distance < min_distance)
		{
			min_distance = distance;
			index = i;
		}
	}

	return index;
}

// 判断聚类结果中簇和簇之间重叠的比例是否超过了预设定的阈值
bool VetKmeans::_isMerged(const vetPoints &points, const vector<int> &clusters_index,
	unsigned int k, double overlap)
{
	if(k == 1)
		return false;

	vector<Point> clusters_means(k);
	vector<Rect> clusters_bounding_box;

	_updateClustersMeans(points, clusters_index, clusters_means);
	_findClustersBoundingBox(points, clusters_index, clusters_bounding_box, k);

	for(unsigned int i = 0; i < k - 1; i++)
	{
		const Rect &box_i = clusters_bounding_box[i];
		const Point &mean_i = clusters_means[i];

		for(unsigned int j = i + 1; j < k; j++)
		{
			const Rect &box_j = clusters_bounding_box[j];
			const Point &mean_j = clusters_means[j];

			double center_dist = _calcDistance(mean_i, mean_j);

			double area_ext_x = (box_j.width + box_i.width) / 2;
			double area_ext_y = (box_j.height + box_i.height) / 2;
			double area_ext = sqrt(area_ext_x * area_ext_x + area_ext_y * area_ext_y);

			if(area_ext >= center_dist * overlap)
				return true;
		}
	}

	return false;
}

// 找到每个簇的最大外接矩形
void VetKmeans::_findClustersBoundingBox(const vetPoints &points, const vector<int> &clusters_index,
	vector<Rect> &clusters_bounding_box, unsigned int k)
{
	vector<Point> tl_vec(k, Point(9999, 9999));
	vector<Point> br_vec(k, Point(0, 0));

	clusters_bounding_box.clear();

	for(unsigned int i = 0; i < clusters_index.size(); i++)
	{
		if(points[i].x < tl_vec[clusters_index[i]].x)
			tl_vec[clusters_index[i]].x = points[i].x;
		
		if(points[i].y < tl_vec[clusters_index[i]].y)
			tl_vec[clusters_index[i]].y = points[i].y;
		
		if(points[i].x > br_vec[clusters_index[i]].x)
			br_vec[clusters_index[i]].x = points[i].x;

		if(points[i].y > br_vec[clusters_index[i]].y)
			br_vec[clusters_index[i]].y = points[i].y;
	}

	for(unsigned int i = 0; i < k; i++)
	{
		clusters_bounding_box.push_back( Rect(tl_vec[i], br_vec[i]) );
	}
}