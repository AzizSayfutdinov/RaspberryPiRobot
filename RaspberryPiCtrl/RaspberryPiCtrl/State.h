#pragma once
#include "Handler.h"

class State
{
protected:
	bool active = true;		// default
	Handler* handler;

public:
	virtual void execute() = 0;
	bool isActive();
	void setActive(bool active);

};

