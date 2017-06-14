/**
 * 策略模式: 定义派生出各个策略的基类
 */

#ifndef VETUSERSTRATEGY_H
#define VETUSERSTRATEGY_H

#include "vetdetectorstrategy.h"
#include "vetdetectorfactory.h"
#include "globals.h"

class VetUserStrategy
{
public:
	VetUserStrategy();
	virtual ~VetUserStrategy();

public:
	virtual void start(std::string path) = 0;
};

#endif	// VETUSERSTRATEGY_H