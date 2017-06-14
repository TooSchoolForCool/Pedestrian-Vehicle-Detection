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
* \file vetutils.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

/**
 * 定义了相关辅助功能函数
 */

#ifndef VETUTILS_H
#define VETUTILS_H

#include "vetroi.h"
#include "veterror.h"
#include "globals.h"

#include <opencv2/opencv.hpp>

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#define COLOR_BLUE 	cv::Scalar(255, 0, 0)
#define COLOR_GREEN	cv::Scalar(0, 255, 0)
#define COLOR_RED 	cv::Scalar(0, 0, 255)

#define KEY_ESC		27
#define KEY_SPACE	32

// 命令行参数解析
void parseArgs(int argc, char **argv);

// 输出帮助文档
void usage();

// 在图像上写入检测信息
void drawRectangles(cv::Mat &frame, const std::vector<VetROI> &rois,
	const cv::Scalar &color, std::string label="");

// Non-Maximum Suppression
void NMS(std::vector<VetROI> &rois, double overlap_threshold);

// 3通道直方图均衡化
void equalizeHist4ColorImage(const cv::Mat &srcImg, cv::Mat &dstImg);

// 输出检测结果到控制台
void printVetROI(std::vector<VetROI> &rois);


#endif	// VETUTILS_H