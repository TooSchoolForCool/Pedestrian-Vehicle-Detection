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
	   	optFlowTester,						// OPT_FLOW_TESTER
	   	cascadeHumanTester,					// CASCADE_HUMAN_TESTER
	   	trackerTester,						// TRACKER_TESTER
	   	capstoneTester,						// CAPSTONE_TESTER
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

	ptr_test_process[CAPSTONE_TESTER](path);

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

void optFlowTester(string video_path)
{
	VetDetectorFactory detector_factory;
	VetFastVideoCapture fvs(video_path, 128);

	int frame_cnt = 1;
	Mat frame;
	vector<VetROI> rois, temp_rois;

	if( !fvs.isOpened() )
		error(string("Cannot open video:") + video_path);

	VetOptFlowDetector optFlowDetector;

	printf("OPT_FLOW_TESTER starts.\n");

	fvs.start();

	namedWindow("frame");
	moveWindow("frame", 25, 25);

	while( fvs.more() )
	{
		if ( fvs.read(frame) )
		{
			if(frame_cnt++ % 2 == 0)
				continue;

			optFlowDetector.detect(frame, rois);
			
			// drawRectangles(frame, rois, COLOR_RED);
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

	printf("OPT_FLOW_TESTER ends.\n");
}

void cascadeHumanTester(string video_path)
{
	VetDetectorFactory detector_factory;
	VetFastVideoCapture fvs(video_path, 128);

	Mat frame;
	vector<VetROI> cascade_res, haar_res;

	VetDetectorStrategy *human_cascade_detector = detector_factory.createDetector(CASCADE_DETECTOR, FULLBODY);
	VetDetectorStrategy *human_haar_detector = detector_factory.createDetector(HAAR_DETECTOR, FULLBODY);

	printf("CASCADE_HUMAN_TESTER starts.\n");

	fvs.start();

	namedWindow("frame");
	moveWindow("frame", 25, 25);

	while( fvs.more() ){
		if ( fvs.read(frame) )
		{
			human_cascade_detector->detect(frame, cascade_res);
			human_haar_detector->detect(frame, haar_res);

			NMS(cascade_res, 0.3);
			NMS(haar_res, 0.3);

			drawRectangles(frame, haar_res, COLOR_RED);
			drawRectangles(frame, cascade_res, COLOR_GREEN);

			cascade_res.clear();
			haar_res.clear();

			imshow("frame", frame);
		}

		char resp = waitKey(5);

		if(resp == KEY_ESC)
		{
			cout << "window: frame closed" << endl;
			destroyWindow("frame");
			break;
		}
		else if(resp == KEY_SPACE)
		{
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	fvs.stop();

	delete human_cascade_detector;
	delete human_haar_detector;

	printf("CASCADE_HUMAN_TESTER ends.\n");
}

void trackerTester(string video_path)
{
	printf("TRACKER_TESTER starts.\n");

	VetDetectorFactory detector_factory;
	VetFastVideoCapture fvs(video_path, 128);

	Mat frame;
	vector<VetROI> rois_car, rois_human, temp_rois;

	if( !fvs.isOpened() )
		error(string("Cannot open video:") + video_path);

	VetDetectorStrategy *human_detector = detector_factory.createDetector(CASCADE_DETECTOR, FULLBODY);

	VetDetectorStrategy *front_car_detector = detector_factory.createDetector(HAAR_DETECTOR, FRONT_CAR);
	VetDetectorStrategy *rear_car_detector = detector_factory.createDetector(HAAR_DETECTOR, REAR_CAR);

	VetTracker human_tracker(0.8, 2, 1, 2);
	VetTracker car_tracker(0.8, 2, 1, 2);

	fvs.start();

	namedWindow("frame");
	moveWindow("frame", 25, 25);

	while( fvs.more() )
	{
		if ( fvs.read(frame) )
		{
			front_car_detector->detect(frame, temp_rois);
			rois_car.insert(rois_car.end(), temp_rois.begin(), temp_rois.end());

			rear_car_detector->detect(frame, temp_rois);
			rois_car.insert(rois_car.end(), temp_rois.begin(), temp_rois.end());

			human_detector->detect(frame, rois_human);

			NMS(rois_car, 0.3);
			NMS(rois_human, 0.3);
			drawRectangles(frame, rois_car, COLOR_RED);
			drawRectangles(frame, rois_human, COLOR_RED);

			human_tracker.update(rois_human);
			car_tracker.update(rois_car);
			drawRectangles(frame, rois_car, COLOR_GREEN);
			drawRectangles(frame, rois_human, COLOR_BLUE);
			
			rois_car.clear();
			rois_human.clear();

			imshow("frame", frame);
		}

		char resp = waitKey(5);

		if(resp == KEY_ESC)
		{
			cout << "window: frame closed" << endl;
			destroyWindow("frame");
			break;
		}
		else if(resp == KEY_SPACE)
		{
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	fvs.stop();

	delete human_detector;
	delete rear_car_detector;
	delete front_car_detector;

	printf("TRACKER_TESTER ends.\n");
}

void capstoneTester(std::string video_path)
{
	printf("CAPSTONE_TESTER starts.\n");

	VetDetectorFactory detector_factory;
	VetFastVideoCapture fvs(video_path, 128);

	VetOptFlowDetector optFlowDetector;
	VetDetectorStrategy *human_detector = detector_factory.createDetector(CASCADE_DETECTOR, FULLBODY);
	VetDetectorStrategy *front_car_detector = detector_factory.createDetector(HAAR_DETECTOR, FRONT_CAR);
	VetDetectorStrategy *rear_car_detector = detector_factory.createDetector(HAAR_DETECTOR, REAR_CAR);

	VetTracker human_tracker(0.8, 2, 1, 2);
	VetTracker car_tracker(0.8, 2, 1, 2);

	Mat frame;
	vector<VetROI> rois_car, rois_opt, rois_human, temp_rois;
	
	int cnt = 0;

	if( !fvs.isOpened() )
		error(string("Cannot open video:") + video_path);

	fvs.start();

	namedWindow("frame");
	moveWindow("frame", 25, 25);

	// VideoWriter writer("VideoTest.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0, Size(1280, 720));

	while( fvs.more() )
	{
		if ( fvs.read(frame) )
		{
			if(cnt++ % 2 == 1)
				continue;
			
			front_car_detector->detect(frame, temp_rois);
			rois_car.insert(rois_car.end(), temp_rois.begin(), temp_rois.end());

			rear_car_detector->detect(frame, temp_rois);
			rois_car.insert(rois_car.end(), temp_rois.begin(), temp_rois.end());

			human_detector->detect(frame, rois_human);

			optFlowDetector.detect(frame, rois_opt);

			NMS(rois_car, 0.3);
			NMS(rois_human, 0.3);

			human_tracker.update(rois_human);
			car_tracker.update(rois_car);

			drawRectangles(frame, rois_opt, COLOR_RED);
			drawRectangles(frame, rois_car, COLOR_GREEN);
			drawRectangles(frame, rois_human, COLOR_BLUE);
			
			rois_opt.clear();
			rois_car.clear();
			rois_human.clear();
			
			// writer << frame;
			imshow("frame", frame);
		}

		char resp = waitKey(30);

		if(resp == KEY_ESC)
		{
			cout << "window: frame closed" << endl;
			destroyWindow("frame");
			break;
		}
		else if(resp == KEY_SPACE)
		{
			cout << "window: frame paused" << endl;
			cout << "Press any key to continue..." << endl;
			waitKey(-1);
		}
	}

	fvs.stop();

	delete human_detector;
	delete rear_car_detector;
	delete front_car_detector;

	printf("CAPSTONE_TESTER ends.\n");
}

void fooTester(string video_path)
{
	printf("FOO_TESTER starts.\n");

	cout << "Hello world." << endl;

	printf("FOO_TESTER ends.\n");
}