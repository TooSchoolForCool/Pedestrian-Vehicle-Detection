#ifndef VETUSERCONTEXT_H
#define VETUSERCONTEXT_H

#include "vetuserstrategy.h"
#include "vettestmode.h"

#include <iostream>
#include <string>


#define TEST_TRIMED_VIDEO_PATH "../data/video/HPIM0026_Trimed.mov"


class VetUserContext
{
public:
	VetUserContext(UserMode user_mode);
	~VetUserContext();

public:
	void start(std::string path);

private:
	VetUserStrategy *ptr_user_strategy_;
};

#endif	// VETUSERCONTEXT_H