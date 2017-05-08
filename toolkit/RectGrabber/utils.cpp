#include "utils.h"

using namespace std;
using namespace cv;

/**
 * Command Line Arguments define here
 */
#define HELP 				'h'
#define VIDEO_SRC 			'c'
#define OUTPUT_DST			'o'
#define TRACE_TARGET		1001

char short_opts[] = "hc:o:";
static struct option long_opts[] = {
	{"help", no_argument, NULL, HELP},
	{"TraceTarget", no_argument, NULL, TRACE_TARGET}
};

void mouseEvent(int event, int x, int y, int flags, void *param)
{
	MouseEventParam *event_param = (MouseEventParam *)param;

	Rect &drawing_box = event_param->rect_;
	MouseAction &mouse_action = event_param->action_;

	switch(event)
	{
		case CV_EVENT_LBUTTONDOWN: 
			drawing_box.x = x;
			drawing_box.y = y;
			drawing_box.width = 0;
			drawing_box.width = 0;

			mouse_action = DRAWING;
			break;
		case CV_EVENT_MOUSEMOVE:
			if(mouse_action == DRAWING)
			{
				drawing_box.width = x - drawing_box.x;
				drawing_box.height = y - drawing_box.y;
			}
			break;
		case CV_EVENT_LBUTTONUP:
			if(mouse_action == DRAWING)
			{
				drawing_box.width = x - drawing_box.x;
				drawing_box.height = y - drawing_box.y;
				
				mouse_action = DONE;
			}
			break;
		default:
			break;
	}

	return;
}

void parseArgs(int argc, char **argv)
{
	int opt;
	int opt_index;

	while( (opt = getopt_long(argc, argv, short_opts, long_opts, &opt_index)) != EOF )
	{
		switch(opt)
		{
			case HELP:
				usage();
				break;
			case VIDEO_SRC:
				strcpy(_video_src_, optarg);
				break;
			case OUTPUT_DST:
				strcpy(_output_dst_, optarg);
				break;
			case TRACE_TARGET:
				_trace_target_ = true;
				break;
			default:
				char msg[512];
				sprintf(msg, "[util.cpp parseArgs()] no such option '-%s'", argv[opt_index]);
				cout << msg << endl;
				exit(1);
				break;
		}
	}

	if(_output_dst_[0] == '\0')
	{
		sprintf(_output_dst_, "output.txt");
	}
}

void usage()
{
	string out = "";

	out += "OVERVIEW: RectGrabber\n\n";

	out += "USAGE: ./RectGrabber [options] -c <video_file_path>\n";
	out += "args in [] is optional, args in <> is mandatory\n\n";

	out += "OPTIONS:\n";
	out += "-h                    Print helping manual\n";
	out += "-c <video_file_path>  Define video file path";
	out += "-o <out file name>    Define output file name\n";
	out += "--help                Print helping manual\n";
	out += "--TraceTarget         Trace target (print coordinates in terminal)\n";

	cout << out << endl;
	exit(0);
}