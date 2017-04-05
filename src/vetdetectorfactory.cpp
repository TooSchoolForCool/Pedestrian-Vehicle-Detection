#include "vetdetectorfactory.h"

using namespace std;
using namespace cv;

VetDetectorFactory::VetDetectorFactory()
{
	// ...
}

VetDetectorFactory::~VetDetectorFactory()
{
	// ...
}

VetDetectorStrategy *VetDetectorFactory::createDetector(DetectorType detector_type,
	DetectedObject detected_object)
{
	switch(detector_type)
	{
		case HAAR_DETECTOR:
			cout << "[VetDetectorFactory::createDetector]: Create Haar Detector" << endl;
			return new VetHaarDetector(detected_object);
			break;
		default:
			cout << "No Such Detector Option" << endl;
			return NULL;
			break;
	}
}