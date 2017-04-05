#ifndef VETTESTMODE_H
#define VETTESTMODE_H

#include "vetuserstrategy.h"
#include "vetdetectorstrategy.h"
#include "vethaardetector.h"
#include "vetcolordetector.h"
#include "vetoptflowdetector.h"
#include "vetimagetoolkit.h"
#include "vetconcurrentqueue.h"
#include "vetfastvideocapture.h"
#include "vetroi.h"
#include "veterror.h"

#include <opencv2/opencv.hpp>

#include <iostream>

class VetTestMode: public VetUserStrategy
{
public:
	VetTestMode();
	~VetTestMode();

private:
	void start(std::string path);
};

#endif