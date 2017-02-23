/**
* [
*  Copyright (c) 2016 by Vehicle-Eye Technology
*  ALL RIGHTS RESERVED.
*
*  The software and information contained herein are proprietary to,  and comprise
*  valuable trade secrets of, Vehicle-Eye Technology.  Disclosure of the software
*  and information will materially harm the business of Vehicle-Eye Technology.
*  This software is furnished pursuant to a written development agreement and may
*  be used, copied, transmitted, and stored only in accordance with the terms of
*  such agreement and with the inclusion of the above copyright notice.  This
*  software and information or any other copies thereof may not be provided or
*  otherwise made available to any other party.
* ]
*/


/*!
* \file vetfastvideocapture.cpp
* \author [Zeyu Zhang]
* \version [0.1]
* \date 2016-02-22
*/

#include "vetfastvideocapture.h"

#include <opencv2/opencv.hpp>

#include <pthread.h>

using namespace std;
using namespace cv;

void* update(void *ptr)
{
	int ret;
	Mat frame;
	
	VetFastVideoCapture *ptr_fvc = (VetFastVideoCapture *)ptr;

	while( !ptr_fvc->stopped_ ){
		if(ptr_fvc->queue_.size() != ptr_fvc->queue_max_size_){
			
			ret = ptr_fvc->video_stream_.read(frame);

			if(ret == 0){
				ptr_fvc->stopped_ = true;
				return NULL;
			}

			ptr_fvc->queue_.push(frame);
		}
	}
	return NULL;
}

VetFastVideoCapture::VetFastVideoCapture(string video_path, 
	int queue_max_size): video_stream_(video_path)
{
	queue_max_size_ = queue_max_size;
	stopped_ = false;
	video_path_ = video_path;
}

VetFastVideoCapture::~VetFastVideoCapture()
{
	video_stream_.release();
}

void VetFastVideoCapture::start()
{
	// cout << "VetFastVideoCapture::start" << endl;
	// cout << "queue_max_size_: " << queue_max_size_ << endl;
	// cout << "stopped_: " << stopped_ << endl;
	// cout << "queue size: " << queue_.size() << endl;

	int ret = pthread_create(&pid_, NULL, update, this);
	if(ret != 0)
		cout << "VetFastVideoCapture::start: Cannot open thread" << endl;
	else
		cout << "VetFastVideoCapture::start: thread created" << endl;
}

bool VetFastVideoCapture::read(Mat &frame)
{
	// cout << "VetFastVideoCapture::read: outside if-statement" << endl;
	if( !queue_.empty() ){
		// cout << "VetFastVideoCapture::read: before read frame" << endl;
		queue_.front(frame);
		// cout << "VetFastVideoCapture::read: read frame is done" << endl;

		// cout << "VetFastVideoCapture::read: before pop queue" << endl;
		queue_.pop();
		// cout << "VetFastVideoCapture::read: pop queue is done" << endl;
		return true;
	}

	return false;
}

void VetFastVideoCapture::stop()
{
	stopped_ = true;
	pthread_join(pid_, NULL);
	cout << "Thread joined" << endl;
}

bool VetFastVideoCapture::isStopped()
{
	return stopped_;
}