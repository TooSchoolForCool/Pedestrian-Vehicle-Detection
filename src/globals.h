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
* \file globals.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-05-23
*/

// Some globals variables are declared here.

/**
 * 该文件中定义了一些全局变量，和使用这些变量的一些结构体的定义
 */

#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>

// 定义用户模式的枚举变量
typedef enum _UserMode
{
	TEST_MODE,
	EVALUATE_MODE,
	USER_MODE
}UserMode;

// 全局变量 main.cpp 中定义: 视频文件读入路径
extern char VIDEO_PATH[1024];
// 全局变量 main.cpp 中定义: 是否开启行人检测
extern bool ENABLE_PEDESTRIAN;
// 全局变量 main.cpp 中定义: 是否开启车辆检测
extern bool ENABLE_VEHICLE;
// 全局变量 main.cpp 中定义: 是否开启光流检测
extern bool ENABLE_OPTFLOW;
// 全局变量 main.cpp 中定义: 是否输出一些debug信息
extern bool ENABLE_DEBUG;
// 全局变量 main.cpp 中定义: 运行模式
extern UserMode EXEC_MODE;

/**
 * Tester Video File Path
 */
#define TEST_VIDEO_PATH "../data/video/HPIM0026.mov"
#define TEST_VIDEO_PATH_2 "../data/video/HPIM0096.mov"
#define TEST_TRIMED_VIDEO_PATH "../data/video/HPIM0026_Trimed.mov"
#define TEST_PEOPLE_VIDEO_PATH "../data/video/HPIM0026_people.mp4"

/**
 * Tester Picture File Path
 */
#define PIC_NMS_PATH "../data/images/nms.jpg"
#define PIC_RED_REGION_TEST_PATH "../data/images/red_region_test.jpg"

#endif