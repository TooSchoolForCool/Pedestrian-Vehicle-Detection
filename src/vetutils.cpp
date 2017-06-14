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
* \file vetimagetoolkit.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#include "vetutils.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <algorithm>

#include <string.h>

using namespace std;
using namespace cv;

/**
 * Command Line Arguments define here
 * 配置命令行解析参数
 */
#define HELP 				'h'
#define SRC 				'c'
#define PEDESTRIAN          1001
#define VEHICLE             1002
#define OPTFLOW 			1003
#define DEBUG				1004
#define MODE				1005

char short_opts[] = "hc:";
static struct option long_opts[] = {
	{"help", no_argument, NULL, HELP},
	{"pedestrian", no_argument, NULL, PEDESTRIAN},
	{"vehicle", no_argument, NULL, VEHICLE},
	{"optflow", no_argument, NULL, OPTFLOW},
	{"debug", no_argument, NULL, DEBUG},
	{"mode", required_argument, NULL, MODE}
};

// 命令行参数解析
void parseArgs(int argc, char **argv)
{
	int opt;
	int opt_index;

	while( (opt = getopt_long(argc, argv, short_opts, long_opts, &opt_index)) != EOF )
	{
		switch(opt)
		{
			case HELP:
				usage();
				break;
			case SRC:
				strcpy(VIDEO_PATH, optarg);
				break;
			case PEDESTRIAN:
				ENABLE_PEDESTRIAN = true;
				break;
			case VEHICLE:
				ENABLE_VEHICLE = true;
				break;
			case OPTFLOW:
				ENABLE_OPTFLOW= true;
				break;
			case DEBUG:
				ENABLE_DEBUG = true;
				break;
			case MODE:
				if(strcmp(optarg, "test") == 0)
					EXEC_MODE = TEST_MODE;
				else if(strcmp(optarg, "eval") == 0)
					EXEC_MODE = EVALUATE_MODE;
				else if(strcmp(optarg, "user") == 0)
					EXEC_MODE = USER_MODE;
				else
				{
					char msg[512];
					sprintf(msg, "[vetutils.cpp parseArgs()] no such mode '%s'", optarg);
					error(msg);
				}
				break;
			default:
				char msg[512];
				sprintf(msg, "[vetutils.cpp parseArgs()] no such option '-%s'", argv[opt_index]);
				error(msg);
				break;
		}
	}
}

// 输出帮助文档
void usage()
{
	string out = "";

	out += "OVERVIEW: [ADAS] Pedestrian & Vehicle Detection\n\n";

	out += "USAGE: ./launch [options]\n";
	out += "args in [] is optional, args in <> is mandatory\n\n";

	out += "OPTIONS:\n";
	out += "-h                    Print helping manual\n";
	out += "-c <video src path>   Define video srouce path\n";
	out += "--help                Print helping manual\n";
	out += "--pedestrian          Enable pedestrian detection\n";
	out += "--vehicle             Enable vehicle detection\n";
	out += "--optflow             Enable optical flow detection\n";
	out += "--debug               Print out some debug info\n";

	cout << out << endl;
	exit(0);
}

bool compareCvRect(const VetROI &a, const VetROI &b)
{
	// int a_y2 = a.br().y;
	// int b_y2 = b.br().y;

	// return a_y2 < b_y2;

	return a.area() > b.area();
}

// 在图像上写入检测信息
void drawRectangles(Mat &frame, const vector<VetROI> &rois,
	const Scalar &color, string label)
{
	if( !rois.empty() )
	{
		vector<VetROI>::const_iterator roi = rois.begin();
		vector<VetROI>::const_iterator end = rois.end();

		while(roi != end)
		{
			rectangle(frame, roi->rect(), color, 2);

			if(roi->label() != "")
			{
				putText(frame, roi->label(), roi->tl(), FONT_HERSHEY_TRIPLEX , 1.3, color); 
			}
			else if(label != "")
			{
				putText(frame, label, roi->tl(), FONT_HERSHEY_TRIPLEX , 1.3, color); 
			}
			roi++;
		}
	}
}

// Non-Maximum Suppression
void NMS(vector<VetROI> &rois, double overlap_threshold)
{
	if( rois.empty() )
		return;

	// initilize picked-up region vector, where we store the NMS result
	vector<VetROI> pick;

	// sort the bounding boxes by the bottom-right 
	// y-coordinate of the bounding box
	sort(rois.begin(), rois.end(), compareCvRect);

	while( !rois.empty() ){
		// At the begining of each iteration, choose the last
		// bounding box as the picked-up region and push it into 
		// the pick vector. Then erase the picked-up last one in 
		// the rois vector.
		VetROI cur_rect = rois[rois.size() - 1];
		pick.push_back(cur_rect);
		rois.erase(rois.end() - 1);

		vector<VetROI>::iterator iter = rois.begin();
		while(iter != rois.end()){
			// find the overlap bounding box top-left & bottom-right coordinates
			// 计算连个矩形宽重叠区域坐标
			int overlap_x1 = max(cur_rect.tl().x, iter->tl().x);
			int overlap_y1 = max(cur_rect.tl().y, iter->tl().y);
			int overlap_x2 = min(cur_rect.br().x, iter->br().x);
			int overlap_y2 = min(cur_rect.br().y, iter->br().y);

			// compute the width and height of the overlap between
			// computed bounding box(cur_rect) and the bounding box(iter)
			// 计算重叠区域的长和宽
			int overlap_width = max(0, overlap_x2 - overlap_x1 + 1);
			int overlap_height = max(0, overlap_y2 - overlap_y1 + 1);

			// compute the ratio of overlap between the computed
			// bounding box(cur_rect) and the bounding box(iter) in the rois
			// 计算重叠区域面和重叠比例
			double overlap_area = (float)(overlap_width * overlap_height);
			double overlap_rate = max(overlap_area / cur_rect.area(), overlap_area / iter->area());
			
			// if there is sufficient overlap, suppress the
			// current bounding box(iter)
			if(overlap_rate > overlap_threshold)
				iter = rois.erase(iter);
			else
				iter++;
		}
	}

	// update the region of interests
	rois.swap(pick);
}

// 3通道直方图均衡化
void equalizeHist4ColorImage(const Mat &srcImg, Mat &dstImg)
{
	vector<Mat> channels;  
	vector<Mat> combinedImg;  

	split(srcImg, channels);  

	for(vector<Mat>::iterator iter = channels.begin(); 
		iter != channels.end(); iter++)
	{
		equalizeHist(*iter, *iter);
	}

	combinedImg.insert(combinedImg.end(), channels.begin(), channels.end()); 

	merge(combinedImg, dstImg);
}

// 输出检测结果到控制台
void printVetROI(vector<VetROI> &rois)
{
	for(unsigned int i = 0; i < rois.size(); i++)
	{
		const VetROI &roi = rois[i];
		
		cout << "[" << roi.label() << "]: " << roi.rect() << endl;
	}
}