/*********************************************************************
 * MODULE: utils.h
 * PURPOSE: Some utility functions and global variables are declared
 *		here.
 * AUTHER: Zeyu Zhang
 * DATE STARTED: 2017-05-08
 *********************************************************************/

#ifndef _UTILS_H
#define _UTILS_H

#include <opencv2/opencv.hpp>

#include <iostream>

#include <stdio.h>
#include <getopt.h>
#include <string.h>

extern char _video_src_[1024];
extern char _output_dst_[1024];
extern char _target_name_[1024];
extern bool _trace_target_;

typedef enum _MouseAction
{
	DRAWING,
	DONE,
	WAIT_NEXT
}MouseAction;

typedef struct _MouseEventParam
{
	cv::Rect rect_;
	MouseAction action_;
}MouseEventParam;

void mouseEvent(int event, int x, int y, int flags, void *param);
void parseArgs(int argc, char ** argv);
void usage();
void writeTargets2file(std::ofstream &outfile, const std::vector<cv::Rect> &targets,
	int frame_counter);
void mouseActionReactor(MouseEventParam &mouse_param, cv::Mat &frame,
	std::vector<cv::Rect> &targets);

#endif	//_UTILS_H