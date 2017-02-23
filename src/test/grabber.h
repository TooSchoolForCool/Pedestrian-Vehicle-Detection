#ifndef _GRABBER_H
#define _GRABBER_H

#include "vetconcurrentqueue.h"

#include <iostream>
#include <queue>

#include <pthread.h>

class Grabber
{
public:
	Grabber(int maxSize);
	~Grabber();

public:
	void start();
	void stop();
	int read(int &obj);

	VetConcurrentQueue<int> queue_;

	pthread_t pid_;

	bool stopped_;
	int maxSize_;
};

#endif