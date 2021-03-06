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

// 线程运行的函数，读取图像帧
void* update(void *ptr)
{
	int ret;
	Mat frame;
	
	VetFastVideoCapture *ptr_fvc = (VetFastVideoCapture *)ptr;

	while( !ptr_fvc->stopped_ ){
		if(ptr_fvc->queue_.size() != ptr_fvc->queue_max_size_){
			ret = ptr_fvc->video_stream_.read(frame);

			if(ret == 0){
				// printf("update: stopped\n");
				ptr_fvc->stopped_ = true;
				return NULL;
			}
			// resize(frame, frame, cv::Size(720, 480), (0, 0), (0, 0), cv::INTER_LINEAR);
			// printf("update - Before push: queue size: %5d\n", ptr_fvc->queue_.size());
			ptr_fvc->queue_.push(frame.clone());
			// printf("update - Before push: queue size: %5d\n", ptr_fvc->queue_.size());
		}
	}
	return NULL;
}

VetFastVideoCapture::VetFastVideoCapture(string video_path, 
	int queue_max_size)
{
	if(video_path != "")
		video_stream_.open(video_path);
	else
		video_stream_.open(0);
	
	if( !video_stream_.isOpened() )
		error(string("Cannot open video '") + video_path + "'");

	queue_max_size_ = queue_max_size;
	stopped_ = false;
	video_path_ = video_path;
}

VetFastVideoCapture::~VetFastVideoCapture()
{
	video_stream_.release();
}

// 开启线程从视频中读取图像帧
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

// 从队列中读取图像帧
bool VetFastVideoCapture::read(Mat &frame)
{
	// cout << "VetFastVideoCapture::read: outside if-statement" << endl;
	if( !queue_.empty() ){
		// cout << "VetFastVideoCapture::read: before read frame" << endl;
		queue_.front(frame);
		// cout << "VetFastVideoCapture::read: read frame is done" << endl;

		// printf("read - Before pop: queue size: %5d\n", queue_.size());
		// cout << "VetFastVideoCapture::read: before pop queue" << endl;
		queue_.pop();
		// cout << "VetFastVideoCapture::read: pop queue is done" << endl;
		// printf("read - After pop: queue size: %5d\n", queue_.size());
		return true;
	}

	return false;
}

// 关闭线程收回资源
void VetFastVideoCapture::stop()
{
	stopped_ = true;
	pthread_join(pid_, NULL);
	stopped_ = false;
	cout << "Thread joined" << endl;
}

// 判断队列里面是否还有图像帧
bool VetFastVideoCapture::more()
{
	return ( !stopped_ || !queue_.empty() );
}

// 判断视频是否打开成功
bool VetFastVideoCapture::isOpened()
{
	return video_stream_.isOpened();
}