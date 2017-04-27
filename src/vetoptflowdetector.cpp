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
* \file vetoptflowdetector.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-03-24
*/

#include "vetoptflowdetector.h"

using namespace std;
using namespace cv;

VetOptFlowDetector::VetOptFlowDetector()
{
	is_ready_ = false;
	
	// set pyrLK method maximum corner tracked
	pyrLK_max_corners_ = 200;

	// set maximum number of clusters for pyrLK method
	pyrLK_max_clusters_ = 2;

	// set pyrLK approach clusters overlap threshold
	// the greater of this value, the less chance to merge
	pyrLK_clusters_overlap_ = 0.6;

	// pyrLK speed vector filter
	// only when speed vector's distance between lower threshold and
	// upper threshold will be accepted
	distance_lower_threshold_ = 10;
	distance_upper_threshold_ = 128;

	// lower bound of cluster area, any cluster's area
	// less than this threshold will be dumped. 
	cluster_area_threshold_ = 100 * 100;

	// direction reference threshold
	// if the ratio of left-direction vector in the reference region
	// is greater than or equal to this threshold, then we assume the
	// camera is turn right, vice versa.
	direction_ref_threshold_ = 0.55;

	_makeColorPalette();
}

VetOptFlowDetector::~VetOptFlowDetector()
{
	// ...
}

void VetOptFlowDetector::detect(const Mat &frame, vector<VetROI> &rois)
{
	// ...
}

void VetOptFlowDetector::detect(Mat &frame, vector<VetROI> &rois)
{
	vector<OptFlowPyrLKResult> result;
	vector<Point> left_corners, right_corners;
	vector<vector<Point> > clusters;

	rois.clear();

	if( !_optFlowPyrLK(frame, result) )
		return;

	// speed vector filter:
	// some abnormal data will be removed (e.g., like extremely large speed)
	// some trivil data will be removed (e.g., like very small speed)
	// when the camera turn left/right, some vector will be removed according
	// to the direction the camera turned.
	_speedVectorFilter(frame, result);
	
	_printSpeedVector(frame, result);

	_getVectorClusters(result, clusters);
	for(unsigned int i = 0; i < clusters.size(); i++)
	{
		Rect rect = _findBoundingRect(clusters[i]);

		if(rect.area() >= cluster_area_threshold_)
			rois.push_back( VetROI(rect, "Warning") );
	}
}

bool VetOptFlowDetector::optFlowFarneback(const Mat &frame, Mat &flow)
{
	Mat gray_image;
	Mat optical_flow;

	cvtColor(frame, gray_image, CV_BGR2GRAY);

	if( !is_ready_ )
	{
		prev_gray_img_ = gray_image;
		is_ready_ = true;
		return false; 
	}

	calcOpticalFlowFarneback(prev_gray_img_, gray_image, optical_flow, 0.5,
		3, 15, 3, 5, 1.2, 0);

	_motion2color(optical_flow, flow);

	prev_gray_img_ = gray_image;

	return true;
}

bool VetOptFlowDetector::_optFlowPyrLK(const cv::Mat &frame, vector<OptFlowPyrLKResult> &result)
{
	Mat cur_gray_image;

	vector<Point2f> prev_points, next_points;
	vector<uchar> state;
	vector<float> err;

	cvtColor(frame, cur_gray_image, CV_BGR2GRAY);
	if( !is_ready_ )
	{
		cur_gray_image.copyTo(prev_gray_img_);
		is_ready_ = true;
		return false;
	}
	
	if(frame.size() != _mask.size())
	{
		_createMask4Detection(frame);
		printf("VetOptFlowDetector::_optFlowPyrLK creates new mask\n");
	}

	goodFeaturesToTrack(prev_gray_img_, prev_points, pyrLK_max_corners_, 
		0.001, 10, _mask, 3, false, 0.04);

	cornerSubPix(prev_gray_img_, prev_points, Size(10,10), Size(-1,-1), 
		TermCriteria(CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, 0.03));

	calcOpticalFlowPyrLK(prev_gray_img_, cur_gray_image, prev_points, 
		next_points, state, err, Size(31, 31), 3);

	cur_gray_image.copyTo(prev_gray_img_);

	// save result
	_calcSpeedVector(prev_points, next_points, state, result);

	return true;
}

void VetOptFlowDetector::_createMask4Detection(const Mat &frame)
{
	Mat mask(frame.size(), CV_8UC1, Scalar(0));
	
	// detection region
	Rect roi_1(0, frame.rows / 2, frame.cols / 4, frame.rows / 2);
	Rect roi_2(frame.cols * 3 / 4, frame.rows / 2, frame.cols / 4, frame.rows / 2);

	if(ref_region_.area() == 0)
	{
		// pyrLK optflow reference region, to determine 
		// if the camera turn left or turn right
		ref_region_ = Rect(frame.cols * 2 / 5, frame.rows * 3 / 4,frame.cols / 5, frame.rows / 4);
	}

	mask(roi_1).setTo(255);
	mask(roi_2).setTo(255);

	// reference region
	mask(ref_region_).setTo(255);

	mask.copyTo(_mask);
}

void VetOptFlowDetector::_printSpeedVector(cv::Mat &frame, vector<OptFlowPyrLKResult> &result)
{
	for(unsigned int i = 0; i < result.size();i++)
	{
		Point p = result[i].prev_point_;
		Point q = result[i].next_point_;

		double delta_x = p.x - q.x;
		double delta_y = p.y - q.y;

		double angle = atan2( (double)delta_y, (double)delta_x );
		double hypotenuse = sqrt( delta_y * delta_y + delta_x * delta_x );

		q.x = (int) (p.x - 3 * hypotenuse * cos(angle));
		q.y = (int) (p.y - 3 * hypotenuse * sin(angle));

		line(frame, p, q, Scalar(0, 0, 255));

		p.x = (int) (q.x + 9 * cos(angle + PI / 4));
		p.y = (int) (q.y + 9 * sin(angle + PI / 4));
		line(frame, p, q, Scalar(0, 0, 255));

		p.x = (int) (q.x + 9 * cos(angle - PI / 4));
		p.y = (int) (q.y + 9 * sin(angle - PI / 4));
		line(frame, p, q, Scalar(0, 0, 255));
	}
}

void VetOptFlowDetector::_calcSpeedVector(vector<Point2f> prev_p, vector<Point2f> next_p,
	vector<uchar> state, vector<OptFlowPyrLKResult> &result)
{
	OptFlowPyrLKResult tmp;

	for(unsigned int i = 0; i < state.size();i++)
	{
		if(state[i] != 0)
		{
			Point p = Point( (int) prev_p[i].x, (int) prev_p[i].y );
			Point q = Point( (int) next_p[i].x, (int) next_p[i].y );

			tmp.prev_point_ = p;
			tmp.next_point_ = q;
			
			double delta_x = p.x - q.x;
			double delta_y = p.y - q.y;

			double angle = atan2( (double)delta_y, (double)delta_x );
			double hypotenuse = sqrt( delta_y * delta_y + delta_x * delta_x );

			q.x = (int) (p.x - 3 * hypotenuse * cos(angle));
			q.y = (int) (p.y - 3 * hypotenuse * sin(angle));

			tmp.distance_ = _calcDistance(p, q);
			tmp.angle_ = _calcAngleInDegree(p, q);
			tmp.is_left_ = (p.x <= prev_gray_img_.cols / 2 ? true : false);

			result.push_back(tmp);
		}
	}
}

void VetOptFlowDetector::_speedVectorFilter(const Mat &frame, vector<OptFlowPyrLKResult> &result)
{
	int left_vec_cnt = 0, right_vec_cnt = 0, cnt = 0;
	bool is_turn_left = false, is_turn_right = false;

	vector<OptFlowPyrLKResult> ret;

	for(unsigned int i = 0; i < result.size(); i++)
	{
		bool is_saved = true;

		Point p = result[i].prev_point_;
		double distance = result[i].distance_;
		double angle = result[i].angle_;
		
		// erase some trivial vector
		if( distance < distance_lower_threshold_ || distance > distance_upper_threshold_ )
		{
			is_saved = false;
		}
		// determine the moving direction of the camera by counting the
		// direction vector in the reference region
		else if( (p.x >= ref_region_.tl().x - 10) && (p.y >= ref_region_.tl().y - 10)
			&& (p.x <= ref_region_.br().x + 10) && (p.y <= ref_region_.br().y + 10) )
		{
			if( (angle >= 135) && (angle <= 225) )
				left_vec_cnt++;

			if( (angle >= 0) && (angle <= 45) )
				right_vec_cnt++;
			else if( (angle >= 315) && (angle <= 360) )
				right_vec_cnt++;

			cnt++;

			is_saved = false;
		}
		// remove some front-to-back vector
		else if( !result[i].is_left_ )
		{
			if( !( (angle >= 135) && (angle <= 225) ) )
				is_saved = false;
		}
		else if( result[i].is_left_ )
		{
			if( !( ((angle >= 0) && (angle <= 45)) || ((angle >= 315) && (angle <= 360)) )  )
				is_saved = false;
		}
		
		if( is_saved == true )
		{
			ret.push_back(result[i]);
		}
	}

	// determine the moving direction of the camera
	if(cnt != 0)
	{
		if((left_vec_cnt / (double)cnt >= direction_ref_threshold_))
		{
			// cout << "turn right:\t";
			// cout << left_vec_cnt << ", " << cnt << endl;
			is_turn_right = true;
		}
		else if((right_vec_cnt / (double)cnt >= direction_ref_threshold_) )
		{
			// cout << "turn left:\t";
			// cout << right_vec_cnt << ", " << cnt << endl;
			is_turn_left = true;
		}
		else
		{
			// cout << "go straight:\t";
			// cout << left_vec_cnt / (double)cnt << ", " << right_vec_cnt / (double)cnt << ", " << cnt << endl;
		}
	}

	// copy ret to result
	result.clear();
	for(unsigned int i = 0; i < ret.size(); i++)
	{
		if( is_turn_left )
		{
			if( (ret[i].angle_ >= 0) && (ret[i].angle_ <= 45) )
				continue;
			if( (ret[i].angle_ >= 315) && (ret[i].angle_ <= 360) )
				continue;
		}
		else if( is_turn_right && (ret[i].angle_ >= 135) && (ret[i].angle_ <= 225) )
		{
			continue;
		}
		
		result.push_back(ret[i]);
	}
}

void VetOptFlowDetector::_getVectorClusters(const vector<OptFlowPyrLKResult> &result,
	vector<vector<Point> > &clusters)
{
	VetKmeans kmeans;

	vector<Point> left_corners, right_corners;
	vector<vector<Point> > tmp_clusters;

	for(unsigned int i = 0; i < result.size();i++)
	{
		Point p = result[i].prev_point_;

		if( result[i].is_left_ )
			left_corners.push_back(p);
		else
			right_corners.push_back(p);
	}

	if(left_corners.size() > 10)
	{
		kmeans.kmeans(left_corners, tmp_clusters, pyrLK_max_clusters_, pyrLK_clusters_overlap_);
		clusters.insert(clusters.end(), tmp_clusters.begin(), tmp_clusters.end());
	}

	if(right_corners.size() > 10)
	{
		kmeans.kmeans(right_corners, tmp_clusters, pyrLK_max_clusters_, pyrLK_clusters_overlap_);
		clusters.insert(clusters.end(), tmp_clusters.begin(), tmp_clusters.end());
	}
}

void VetOptFlowDetector::_makeColorPalette()
{
    int RY = 15;
    int YG = 6;
    int GC = 4;
    int CB = 11;
    int BM = 13;
    int MR = 6;

	for (int i = 0; i < RY; i++)
		color_palette_.push_back( Scalar(255, 255 * i / RY, 0) );

    for (int i = 0; i < YG; i++)
    	color_palette_.push_back( Scalar(255 - 255*i/YG, 255, 0) );

    for (int i = 0; i < GC; i++)
    	color_palette_.push_back( Scalar(0, 255, 255 * i / GC) );

    for (int i = 0; i < CB; i++)
    	color_palette_.push_back( Scalar(0, 255 - 255*i/CB, 255) );

    for (int i = 0; i < BM; i++)
    	color_palette_.push_back( Scalar(255 * i / BM, 0, 255) );

    for (int i = 0; i < MR; i++)
    	color_palette_.push_back( Scalar(255, 0, 255 - 255*i/MR) );
}

void VetOptFlowDetector::_motion2color(Mat &flow, Mat &color)
{
	if (color.empty())
		color.create(flow.rows, flow.cols, CV_8UC3);

	// determine motion range:
    float maxrad = -1;

	// Find max flow to normalize fx and fy
	for (int i= 0; i < flow.rows; ++i) 
	{
		for (int j = 0; j < flow.cols; ++j) 
		{
			Vec2f flow_at_point = flow.at<Vec2f>(i, j);
			float fx = flow_at_point[0];
			float fy = flow_at_point[1];
			if ((fabs(fx) >  UNKNOWN_FLOW_THRESH) || (fabs(fy) >  UNKNOWN_FLOW_THRESH))
				continue;
			float rad = sqrt(fx * fx + fy * fy);
			maxrad = maxrad > rad ? maxrad : rad;
		}
	}

	for (int i= 0; i < flow.rows; ++i) 
	{
		for (int j = 0; j < flow.cols; ++j) 
		{
			uchar *data = color.data + color.step[0] * i + color.step[1] * j;
			Vec2f flow_at_point = flow.at<Vec2f>(i, j);

			float fx = flow_at_point[0] / maxrad;
			float fy = flow_at_point[1] / maxrad;
			if ((fabs(fx) >  UNKNOWN_FLOW_THRESH) || (fabs(fy) >  UNKNOWN_FLOW_THRESH))
			{
				data[0] = data[1] = data[2] = 0;
				continue;
			}
			float rad = sqrt(fx * fx + fy * fy);

			float angle = atan2(-fy, -fx) / CV_PI;
			float fk = (angle + 1.0) / 2.0 * (color_palette_.size()-1);
			int k0 = (int)fk;
			int k1 = (k0 + 1) % color_palette_.size();
			float f = fk - k0;
			//f = 0; // uncomment to see original color wheel

			for (int b = 0; b < 3; b++) 
			{
				float col0 = color_palette_[k0][b] / 255.0;
				float col1 = color_palette_[k1][b] / 255.0;
				float col = (1 - f) * col0 + f * col1;
				if (rad <= 1)
					col = 1 - rad * (1 - col); // increase saturation with radius
				else
					col *= .75; // out of range
				data[2 - b] = (int)(255.0 * col);
			}
		}
	}
}

double VetOptFlowDetector::_calcDistance(const Point &a, const Point &b)    
{    
    double distance;

    distance = powf((a.x - b.x),2) + powf((a.y - b.y),2);    
    distance = sqrtf(distance);    
    
    return distance;    
}

double VetOptFlowDetector::_calcAngleInDegree(const Point &a, const Point &b)
{
	int delta_x = b.x - a.x;
	int delta_y = b.y - a.y;
	double delta_hypotenuse = sqrt(delta_x * delta_x + delta_y * delta_y);

	double cos_value = delta_x / delta_hypotenuse;

	double angle = acos(cos_value) * 180 / 3.1415;

	// In opencv, y axis is up-side-down
	if(delta_y > 0)
		angle = 360 - angle;

	return angle;
}

Rect VetOptFlowDetector::_findBoundingRect(const vector<Point> &src)
{
	Point tl(9999, 9999), br(0, 0);

	vector<Point>::const_iterator iter = src.begin();
	vector<Point>::const_iterator end = src.end();

	while(iter != end)
	{
		if(iter->x < tl.x)
			tl.x = iter->x;
		
		if(iter->y < tl.y)
			tl.y = iter->y;
		
		if(iter->x > br.x)
			br.x = iter->x;

		if(iter->y > br.y)
			br.y = iter->y;

		iter++;
	}

	return Rect(tl, br);
}