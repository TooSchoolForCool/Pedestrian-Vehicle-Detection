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
* \file main.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#include "vetusercontext.h"
#include "globals.h"
#include "vetutils.h"

#include <opencv2/opencv.hpp>

#include <iostream>

using namespace cv;
using namespace std;

extern char VIDEO_PATH[1024] = "";
extern UserMode EXEC_MODE = USER_MODE;
extern bool ENABLE_PEDESTRIAN = false;
extern bool ENABLE_VEHICLE = false;
extern bool ENABLE_OPTFLOW = false;
extern bool ENABLE_DEBUG = false;

int main(int argc, char **argv)
{	
	parseArgs(argc, argv);

	VetUserContext user(EXEC_MODE);
	user.start(VIDEO_PATH);

	return 0;
}