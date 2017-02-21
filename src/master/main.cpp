#include "vetdetectorcontext.h"
#include "vetdetectorstrategy.h"

#include <opencv2/opencv.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	VetDetectorContext car_detector(HAAR_FRONT_CAR_DETECTOR);

	Mat frame;

	car_detector.detect(frame);

	return 0;
}