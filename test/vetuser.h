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
* \file vetuser.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-05-23
*/

#ifndef VETUSER_H
#define VETUSER_H

#include "vetuserstrategy.h"
#include "vetdetectorstrategy.h"
#include "vethaardetector.h"
#include "vetcolordetector.h"
#include "vetoptflowdetector.h"
#include "vettracker.h"
#include "vetutils.h"
#include "vetconcurrentqueue.h"
#include "vetfastvideocapture.h"
#include "vetroi.h"
#include "veterror.h"
#include "globals.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <fstream>

#include <stdio.h>
#include <unistd.h>

class VetUser: public VetUserStrategy
{
public:
	VetUser();
	~VetUser();

public:
	void start(std::string video_path);
};

#endif	// VETUSER_H