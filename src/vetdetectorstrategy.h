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
* \file vetdetectorstrategy.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-18
*/

/**
 * 本文件定义了派生出各个检测器的基类
 */

#ifndef VETDETECTORSTRATEGY_H
#define VETDETECTORSTRATEGY_H

#include "vetroi.h"
#include "veterror.h"
#include "vetutils.h"

#include <opencv2/opencv.hpp>

#include <iostream>

// 定义检测器类型: 枚举类型
typedef enum _DetectedObject
{
	FRONT_CAR = 1,
	REAR_CAR = 2,
	FULLBODY = 3,
	RED_REGION = 4
}DetectedObject;

/*!
 * \brief Define the xml file path
 */
#define HAAR_CASCADE_FRONT_CAR_XML "../data/haar-cascades/haar_cascade_front_car.xml"
#define HAAR_CASCADE_REAR_CAR_XML "../data/haar-cascades/haar_cascade_rear_car.xml"
#define HAAR_CASCADE_FULLBODY_XML "../data/haar-cascades/vision_art_lbp_human.xml"


/*!
 * \brief The VetDetectorStrategy class
 */
class VetDetectorStrategy
{
public:
	VetDetectorStrategy();
	virtual ~VetDetectorStrategy();

public:
	virtual void detect(const cv::Mat &frame, std::vector<VetROI> &rois) = 0;
};


#endif	// VETDETECTORSTRATEGY_H