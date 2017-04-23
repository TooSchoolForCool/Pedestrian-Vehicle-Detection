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

void VetKmeans::kmeans(const vetPoints &points, std::vector<vetPoints> &clusters, unsigned int k)
{
	vector<int> clusters_index(points.size(), -1);
	vector<Point> clusters_means(k);

	clusters.clear();

	if(points.size() < k)
	{
		k = points.size();
	}

	for(unsigned int i = 0; i < k; i++)
	{
		clusters.push_back( vector<Point>() );
	}

	// Initialize middle point
	for(unsigned int i = 0; i < k; i++)
	{
		// points[i] belongs to cluster #i
		clusters_index[i] = i;
		// the middle point of cluster #i is points[i]
		clusters_means[i] = points[i];
	}

	while(_updateClustersIndex(points, clusters_index, clusters_means))
	{
		_updateClustersMeans(points, clusters_index, clusters_means);
	}

	for(unsigned int i = 0; i < points.size(); i++)
	{
		clusters[clusters_index[i]].push_back(points[i]);
	}
}

double VetKmeans::_calcDistance(const cv::Point &a, const cv::Point &b)
{
	double distance;

    distance = powf((a.x - b.x), 2) + powf((a.y - b.y), 2);    
    distance = sqrtf(distance);    
    
    return distance;   
}

bool VetKmeans::_updateClustersIndex(const vetPoints &points, vector<int> &clusters_index,
	const vector<Point> &clusters_means)
{
	bool isChanged = false;

	for(int i = 0; i < clusters_index.size(); i++)
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

void VetKmeans::_updateClustersMeans(const vetPoints &points, const vector<int> &clusters_index,
	vector<Point> &clusters_means)
{
	vector<int> clusters_cnt(clusters_means.size(), 0);

	for(int i = 0; i < clusters_means.size(); i++)
	{
		clusters_means[i] = Point(0, 0);
	}

	for(int i = 0; i < clusters_index.size(); i++)
	{
		clusters_means[clusters_index[i]].x += points[i].x;
		clusters_means[clusters_index[i]].y += points[i].y;

		clusters_cnt[clusters_index[i]]++;
	}

	for(int i = 0; i < clusters_means.size(); i++)
	{
		if(clusters_cnt[i] != 0)
		{
			clusters_means[i].x /= clusters_cnt[i];
			clusters_means[i].y /= clusters_cnt[i];
		}
	}
}

int VetKmeans::_findClosestCluster(const Point &a, const vector<Point> &clusters_means)
{
	double min_distance = _calcDistance(clusters_means[0], a);
	int index = 0;

	for(int i = 1; i < clusters_means.size(); i++)
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