#include "vetdetectorcontext.h"
#include "vetdetectorstrategy.h"

#include <opencv2/opencv.hpp>

#include <iostream>

using namespace cv;
using namespace std;

void drawRectanles(Mat & img, const vector< Rect > &locations, const Scalar &color)
{
	if (!locations.empty())
	{
		vector< Rect >::const_iterator loc = locations.begin();
		vector< Rect >::const_iterator end = locations.end();
		for (; loc != end; loc++)
		{
			rectangle(img, *loc, color, 2);
		}
	}
}

int main()
{
	VetDetectorContext car_detector(HAAR_FRONT_CAR_DETECTOR);

	Mat frame = imread("../../image-dataset/2.jpg");
	vector<Rect> rois;

	car_detector.detect(frame, rois);

	drawRectanles(frame, rois, Scalar(0, 255, 0));

	imshow("frame", frame);

	while(waitKey(30) != 27)
		continue;

	return 0;
}