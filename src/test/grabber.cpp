#include "grabber.h"

#include <stdio.h>

static int cnt = 0;

Grabber::Grabber(int maxSize)
{
	maxSize_ = maxSize;
	stopped_ = false;
}

Grabber::~Grabber()
{

}

void* update(void *ptr)
{
	Grabber *ptr_grabber = (Grabber *)ptr;

	printf("start\n");

	while( !ptr_grabber->stopped_ ){
		if(ptr_grabber->queue_.size() != ptr_grabber->maxSize_){
			ptr_grabber->queue_.push(cnt++);
			printf("push: %d\tsize: %d\n", cnt - 1, ptr_grabber->queue_.size());
		}
	}
	printf("stop\n");
	return NULL;
}


void Grabber::start()
{
	pthread_create(&pid_, NULL, update, this);
}

void Grabber::stop()
{
	stopped_ = true;
	pthread_join(pid_, NULL);
}

int Grabber::read(int &obj)
{
	if( !queue_.empty() ){
		obj = queue_.front();
		queue_.pop();
		return 0;
	}
	return -1;
}