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
* \file vetroi.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/ 

#ifndef VETROI_H
#define VETROI_H

#include <iostream>

#include <opencv2/opencv.hpp>

class VetROI
{
public:
	VetROI(cv::Rect rect, std::string label);
	~VetROI();

public:


private:
	cv::Rect rect_;
	std::string label_;
};

#endif