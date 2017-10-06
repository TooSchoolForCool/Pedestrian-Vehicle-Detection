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
* \file vetdetectorfactory.h
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2017-04-05
*/

#ifndef VETDETECTORFACTORY_H
#define VETDETECTORFACTORY_H

#include "vetdetectorstrategy.h"
#include "vethaardetector.h"
#include "vetcolordetector.h"
#include "vethogsvmdetector.h"
#include "vetoptflowdetector.h"
#include "vetcascadedetector.h"

#include <opencv2/opencv.hpp>

#include <iostream>

typedef enum _DetectorType
{
	HAAR_DETECTOR,
	HOG_SVM_DETECTOR,
	COLOR_DETECTOR,
	OPT_FLOW_DETECTOR,
	CASCADE_DETECTOR
}DetectorType;

class VetDetectorFactory
{
public:
	VetDetectorFactory();
	~VetDetectorFactory();

public:
	VetDetectorStrategy *createDetector(DetectorType detector_type, 
		DetectedObject detected_object);
};

#endif	// VETDETECTORFACTORY_H

