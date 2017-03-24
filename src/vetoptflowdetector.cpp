#include "vetoptflowdetector.h"

using namespace std;

VetOptFlowDetector::VetOptFlowDetector()
{
	is_ready_ = false;
}

VetOptFlowDetector::~VetOptFlowDetector()
{
	// ...
}

bool VetOptFlowDetector::startTracking(const Mat &frame, Mat &flow)
{
	return false;
}