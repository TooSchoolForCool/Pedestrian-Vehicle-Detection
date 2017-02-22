#include "vetdetectorcontext.h"
#include "vetdetectorstrategy.h"
#include "vetimageprocessor.h"
#include "vettester.h"

#include <opencv2/opencv.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	VetTester tester(NMS_TESTER);
	tester.run();
	return 0;
}