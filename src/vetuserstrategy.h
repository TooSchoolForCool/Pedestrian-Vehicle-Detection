#ifndef VETUSERSTRATEGY_H
#define VETUSERSTRATEGY_H

#include "vetdetectorstrategy.h"
#include "vetdetectorfactory.h"

typedef enum _UserMode
{
	TEST_MODE = 1
}UserMode;

class VetUserStrategy
{
public:
	VetUserStrategy();
	virtual ~VetUserStrategy();

public:
	virtual void start(std::string path) = 0;
};

#endif	// VETUSERSTRATEGY_H