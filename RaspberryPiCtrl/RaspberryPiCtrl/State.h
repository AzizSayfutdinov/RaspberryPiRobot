#pragma once
#include "Handler.h"

class State
{
protected:
	bool periodic = true;		// default
	Handler* handler;

public:
	virtual void execute() = 0;
	bool isPeriodic();
	void setPeriodic(bool active);

};

