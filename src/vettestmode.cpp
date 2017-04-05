#include "vettestmode.h"

using namespace std;
using namespace cv;

VetTestMode::VetTestMode()
{
	cout << "[VetTestMode::VetTestMode]: VetTestMode created" << endl;
}

VetTestMode::~VetTestMode()
{
	cout << "[VetTestMode::~VetTestMode]: VetTestMode deleted" << endl;
}

void VetTestMode::start(string path)
{
	cout << "[VetTestMode::start]: test mode starts" << endl;

	VetFastVideoCapture fvs(path, 128);
	VetDetectorFactory detector_factory;

	Mat frame;
	vector<VetROI> temp_rois, rois;

	VetDetectorStrategy *front_car_detector = detector_factory.createDetector(HAAR_DETECTOR, FRONT_CAR);
	VetDetectorStrategy *rear_car_detector = detector_factory.createDetector(HAAR_DETECTOR, REAR_CAR);

	fvs.start();

	while( fvs.more() ){
		if ( fvs.read(frame) ){
			front_car_detector->detect(frame, temp_rois);
			rois.insert(rois.end(), temp_rois.begin(), temp_rois.end());

			rear_car_detector->detect(frame, temp_rois);
			rois.insert(rois.end(), temp_rois.begin(), temp_rois.end());

			NMS(rois, 0.3);
			drawRectangles(frame, rois, COLOR_RED);
			rois.clear();  

			imshow("frame", frame);
		}

		char resp = waitKey(5);

		if(resp == KEY_ESC){
			cout << "window: frame closed" << endl;
			destroyWindow("frame");
			break;
		}
		else if(resp == KEY_SPACE){
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	fvs.stop();

	cout << "[VetTestMode::start]: test mode ends" << endl;
}