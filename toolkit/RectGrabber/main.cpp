/*********************************************************************
 * MODULE: Rectangle Grabber
 *
 * PURPOSE: RectGrabber is for video labeling. Using your mouse
 * 		pointer rectangle the region, and this program will output
 *		the coordinate of the rectangle region (x, y, width, height)
 *		into the target file.
 *
 *		The output file contains 6 columns as following:
 *			frame#  x  y  width  height  object_name
 *		Each column is separated by a tab charactor '\t'.
 *		
 * AUTHER: Zeyu Zhang
 * DATE STARTED: 2017-05-08
 *********************************************************************/

#include "utils.h"

#include <opencv2/opencv.hpp>

#include <iostream>
#include <fstream>

#include <stdio.h>

using namespace std;
using namespace cv;



int main(int argc, char **argv)
{
	VideoCapture video_stream("HPIM0026_Trimed.mov");

	if( !video_stream.isOpened() )
	{
		printf("[main]: Cannot open video file\n");
		exit(1);
	}


	Mat frame;
	int frame_counter = 1;

	MouseEventParam mouse_param;
	mouse_param.action_ = WAIT;

	namedWindow("frame");
	moveWindow("frame", 25, 25);

	video_stream.read(frame);
	imshow("frame", frame);

	setMouseCallback("frame", mouseEvent, &mouse_param);

	while(1)
	{
		char ret = waitKey(15);
		
		if(ret == 27)
			break;

		if(mouse_param.action_ == DONE)
		{
			cout << mouse_param.rect_ << endl;
			mouse_param.action_ = WAIT;
		}
		else if(mouse_param.action_ == START)
		{
			cout << mouse_param.rect_ << endl;
		}

		switch(ret)
		{
			case 'n':
				video_stream.read(frame);
				break;
			default:
				break;
		}

		imshow("frame", frame);
	}

	cout << "End..." << endl;

	return 0;
}