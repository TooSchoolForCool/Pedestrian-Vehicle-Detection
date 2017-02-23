#include "vetconcurrentqueue.h"
#include "grabber.h"

#include <iostream>

using namespace std;

int main()
{
	int seed;

	Grabber grabber(128);

	grabber.start();

	for(int i = 0; i < 50000; ){
		// cout << "waiting" << endl;
		int ret = grabber.read(seed);
		if(ret == 0){
			printf("pop: %d\tsize: %d\n", seed, grabber.queue_.size());
			i++;
		}
	}

	grabber.stop();
}