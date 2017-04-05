#include "vettestmode.h"

using namespace std;
using namespace cv;

static void (*ptr_test_process[])(string) 
	= {	
		carHaarTester,						// CAR_HAAR_TESTER
	   	NMSTester,							// NMS_TESTER
	   	videoPlayerTester,					// VIDEO_PLAYER_TESTER
	   	fastVideoPlayerTester,				// FAST_VIDEO_PLAYER_TESTER
	   	fastCarHaarTester,					// FAST_CAR_HAAR_TESTER
	   	fastFullbodyHaarTester,				// FAST_FULLBODY_HAAR_TESTER
	   	redDetectorTester,					// RED_DETECTOR_TESTER
	   	fastHOGSVMTester,					// FAST_HOG_SVM_TESTER
	   	fooTester							// FOO_TESTER
	  };

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

	ptr_test_process[FOO_TESTER](path);

	cout << "[VetTestMode::start]: test mode ends" << endl;
}

/*******************************************
 * Tester Functions go below
 *******************************************/

void fastVideoPlayerTester(string video_path)
{
	VetFastVideoCapture fvs(video_path, 128);
	Mat frame;

	printf("FAST_VIDEO_PLAYER_TESTER starts.\n");

	fvs.start();

	while( fvs.more() ){
		if( fvs.read(frame) ){
			imshow("frame", frame);
		}

		char resp = waitKey(5);

		if(resp == KEY_ESC){
			destroyWindow("frame");
			cout << "window: frame closed" << endl;
			break;
		}
		else if(resp == KEY_SPACE){
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	fvs.stop();

	printf("FAST_VIDEO_PLAYER_TESTER ends.\n");
}

void videoPlayerTester(string video_path)
{
	VideoCapture videoStream(video_path);
	Mat frame;

	printf("VIDEO_PLAYER_TESTER starts.\n");

	while(videoStream.read(frame)){
		imshow("frame", frame);

		char resp = waitKey(5);

		if(resp == KEY_ESC){
			destroyWindow("frame");
			cout << "window: frame closed" << endl;
			break;
		}
		else if(resp == KEY_SPACE){
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	printf("VIDEO_PLAYER_TESTER ends.\n");
}

void NMSTester(string image_path)
{
	Mat image = imread(image_path);
	Mat originImg = image.clone();

	vector<VetROI> rois;

	printf("NMS_TESTER starts.\n");

	// Rect(x, y, width, height)
	rois.push_back( Rect(84, 48, 212 - 84, 176 - 48) );
	rois.push_back( Rect(12, 30, 76 - 12, 94 - 30) );
	rois.push_back( Rect(72, 36, 200 - 72, 164 - 36) );
	rois.push_back( Rect(12, 36, 76 - 12, 100 - 36) );

	drawRectangles(originImg, rois, COLOR_GREEN);
	imshow("origin", originImg);

	NMS(rois, 0.3);
	drawRectangles(image, rois, COLOR_GREEN);
	imshow("After NMS", image);

	while(waitKey(30) != KEY_ESC)
		continue;

	destroyWindow("origin");
	destroyWindow("After NMS");

	printf("NMS_TESTER ends.\n");
}

void carHaarTester(string video_path)
{
	VetDetectorFactory detector_factory;
	VideoCapture videoStream(video_path);

	Mat frame;
	vector<VetROI> temp_rois, rois;

	VetDetectorStrategy *front_car_detector = detector_factory.createDetector(HAAR_DETECTOR, FRONT_CAR);
	VetDetectorStrategy *rear_car_detector = detector_factory.createDetector(HAAR_DETECTOR, REAR_CAR);

	printf("CAR_HAAR_TESTER starts.\n");

	while(videoStream.read(frame)){
		front_car_detector->detect(frame, temp_rois);
		rois.insert(rois.end(), temp_rois.begin(), temp_rois.end());

		rear_car_detector->detect(frame, temp_rois);
		rois.insert(rois.end(), temp_rois.begin(), temp_rois.end());

		NMS(rois, 0.3);
		drawRectangles(frame, rois, COLOR_RED);
		rois.clear();  

		imshow("frame", frame);

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

	videoStream.release();	
	delete front_car_detector;
	delete rear_car_detector;

	printf("CAR_HAAR_TESTER ends.\n");
}

void fastCarHaarTester(string video_path)
{
	VetDetectorFactory detector_factory;
	VetFastVideoCapture fvs(video_path, 128);

	Mat frame;
	vector<VetROI> temp_rois, rois;

	VetDetectorStrategy *front_car_detector = detector_factory.createDetector(HAAR_DETECTOR, FRONT_CAR);
	VetDetectorStrategy *rear_car_detector = detector_factory.createDetector(HAAR_DETECTOR, REAR_CAR);

	printf("FAST_CAR_HAAR_TESTER starts.\n");

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
	delete front_car_detector;
	delete rear_car_detector;

	printf("FAST_CAR_HAAR_TESTER ends.\n");
}

void fastFullbodyHaarTester(string video_path)
{
	VetDetectorFactory detector_factory;
	VetFastVideoCapture fvs(video_path, 128);

	Mat frame;
	vector<VetROI> rois;

	VetDetectorStrategy *human_detector = detector_factory.createDetector(HAAR_DETECTOR, FULLBODY);

	printf("FAST_FULLBODY_HAAR_TESTER starts.\n");

	fvs.start();

	while( fvs.more() ){
		if ( fvs.read(frame) ){
			human_detector->detect(frame, rois);

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
	delete human_detector;

	printf("FAST_FULLBODY_HAAR_TESTER ends.\n");
}

void redDetectorTester(string video_path)
{
	VetDetectorFactory detector_factory;
	VetFastVideoCapture fvs(video_path, 128);
	Mat frame;
	vector<VetROI> rois;
	int cnt = 1;

	VetDetectorStrategy *color_detector = detector_factory.createDetector(COLOR_DETECTOR, RED_REGION);

	printf("RED_DETECTOR_TESTER starts.\n");

	fvs.start();

	while( fvs.more() ){
		if ( fvs.read(frame) ){
			// Mat hsvImage;
			color_detector->detect(frame, rois);

			NMS(rois, 0.3);
			drawRectangles(frame, rois, COLOR_RED);
			rois.clear();

			printf("Frame %d\n", cnt++);
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
	delete color_detector;

	printf("RED_DETECTOR_TESTER ends.\n");
}

void fastHOGSVMTester(std::string video_path)
{
	VetDetectorFactory detector_factory;
	VetFastVideoCapture fvs(video_path, 128);
	Mat frame;
	vector<VetROI> rois;

	VetDetectorStrategy *human_detector = detector_factory.createDetector(HOG_SVM_DETECTOR, FULLBODY);

	printf("FAST_HOG_SVM_TESTER starts.\n");

	fvs.start();

	while( fvs.more() ){
		if ( fvs.read(frame) ){
			human_detector->detect(frame, rois);

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
	delete human_detector;

	printf("FAST_HOG_SVM_TESTER ends.\n");
}

void fooTester(string video_path)
{
	VetDetectorFactory detector_factory;
	VetFastVideoCapture fvs(video_path, 128);

	Mat frame;
	Mat flow;
	vector<VetROI> temp_rois, rois;

	if( !fvs.isOpened() )
		error(string("Cannot open video:") + video_path);

	VetDetectorStrategy *front_car_detector = detector_factory.createDetector(HAAR_DETECTOR, FRONT_CAR);
	VetDetectorStrategy *rear_car_detector = detector_factory.createDetector(HAAR_DETECTOR, REAR_CAR);

	VetOptFlowDetector optFlowDetector;

	printf("FOO_TESTER starts.\n");

	fvs.start();

	namedWindow("frame");
	moveWindow("frame", 25, 25);

	while( fvs.more() )
	{
		if ( fvs.read(frame) )
		{
			front_car_detector->detect(frame, temp_rois);
			rois.insert(rois.end(), temp_rois.begin(), temp_rois.end());

			rear_car_detector->detect(frame, temp_rois);
			rois.insert(rois.end(), temp_rois.begin(), temp_rois.end());

			NMS(rois, 0.3);

			optFlowDetector.optFlowPyrLK(frame, flow);

			drawRectangles(frame, rois, COLOR_GREEN);
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
	delete front_car_detector;
	delete rear_car_detector;

	printf("FOO_TESTER ends.\n");
}