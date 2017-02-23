#include "vetdetectorcontext.h"
#include "vetdetectorstrategy.h"
#include "vetimageprocessor.h"
#include "vetconcurrentqueue.h"
#include "vettester.h"

#include <opencv2/opencv.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main()
{	
	VetTester tester(FASTER_VIDEO_PLAYER_TESTER);
	tester.run(TEST_TRIMED_VIDEO_PATH);
	return 0;
}