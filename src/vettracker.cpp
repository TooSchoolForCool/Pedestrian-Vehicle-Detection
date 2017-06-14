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
* \file vettracker.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-04-26
*/

#include "vettracker.h"

#include <opencv2/opencv.hpp>

#include <iostream>

using namespace std;
using namespace cv;

VetTracker::VetTracker(double overlap_threshold, int ack_threshold,
	int unack_threshold, int delete_threshold)
{
	this->overlap_threshold_ = overlap_threshold;
	this->ack_threshold_ = ack_threshold;
	this->unack_threshold_ = unack_threshold;
	this->delete_threshold_ = delete_threshold;
}

VetTracker::~VetTracker()
{
	cout << "[VetTracker::~VetTracker] delete VetTracker" << endl;
}

// 跟新每个检测目标的状态
void VetTracker::update(vector<VetROI> &detected_res)
{
	for(vector<VetROI>::iterator iter_res = detected_res.begin(); iter_res != detected_res.end(); )
	{
		vector<DetectedRegion>::iterator iter_regions = detected_regions_.begin();
		while(iter_regions != detected_regions_.end())
		{
			double overlap_rate = _calcOverlapped(iter_regions->rect_, iter_res->rect());

			if(overlap_rate > overlap_threshold_)
			{
				_updateDetectedRegion(*iter_regions, *iter_res);
				break;
			}

			iter_regions++;
		}

		// did not find threshold-satisfied overlapped region
		if( iter_regions == detected_regions_.end() )
		{
			_addDetectedRegion(*iter_res);
		}

		iter_res = detected_res.erase(iter_res);
	}

	_clearNotExistRegion();
	_getDetectedRegion(detected_res);
	// _clearNotExistRegion();
}

// 获取当前被确认(可显示)的检测目标
void VetTracker::_getDetectedRegion(vector<VetROI> &detected_res)
{
	detected_res.clear();

	vector<DetectedRegion>::iterator iter_regions = detected_regions_.begin();

	while(iter_regions != detected_regions_.end())
	{
		if(iter_regions->ack_ >= ack_threshold_ && iter_regions->unack_ <= unack_threshold_)
		{
			VetROI res(iter_regions->rect_, iter_regions->label_);
			detected_res.push_back(res);
		}

		iter_regions++;
	}
}

// 通过计算重叠比例的方式来匹配检测框
double VetTracker::_calcOverlapped(const Rect &a, const Rect &b)
{
	// find the overlap bounding box top-left & bottom-right coordinates
	int overlap_x1 = max(a.tl().x, b.tl().x);
	int overlap_y1 = max(a.tl().y, b.tl().y);
	int overlap_x2 = min(a.br().x, b.br().x);
	int overlap_y2 = min(a.br().y, b.br().y);

	// compute the width and height of the overlap between
	// computed bounding box(cur_rect) and the bounding box(iter)
	int overlap_width = max(0, overlap_x2 - overlap_x1 + 1);
	int overlap_height = max(0, overlap_y2 - overlap_y1 + 1);

	// compute the maximum ratio of overlap between the area a and area b
	double overlap_area = (float)(overlap_width * overlap_height);
	double overlap_rate = max(overlap_area / a.area(), overlap_area / b.area());

	return overlap_rate;
}

// 更新指定检测目标的状态
void VetTracker::_updateDetectedRegion(DetectedRegion &dst, const VetROI &src)
{
	dst.rect_ = src.rect();
	dst.label_ = src.label();
	dst.ack_++;
	dst.unack_ = 0;
	dst.is_exist_ = true;
}

// 增加新的检测目标
void VetTracker::_addDetectedRegion(const VetROI &src)
{
	DetectedRegion dst;

	dst.rect_ = src.rect();
	dst.label_ = src.label();
	dst.ack_ = 1;
	dst.unack_ = 0;
	dst.is_exist_ = true;

	detected_regions_.push_back(dst);	
}

// 移除检测目标
void VetTracker::_clearNotExistRegion()
{
	vector<DetectedRegion>::iterator iter_regions = detected_regions_.begin();

	while(iter_regions != detected_regions_.end())
	{	
		if(iter_regions->is_exist_ == false)
		{
			iter_regions->ack_--;
			iter_regions->unack_++;
		}
		else
		{
			iter_regions->is_exist_ = false;
		}

		if(iter_regions->unack_ >= delete_threshold_)
		{
			iter_regions = detected_regions_.erase(iter_regions);
		}
		else
		{
			iter_regions++;
		}
	}
}