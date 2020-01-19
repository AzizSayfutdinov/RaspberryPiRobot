#pragma once
#include "Robot.h"

class State
{
protected:
	bool active = false;		// default
	Robot* robot;

public:
	virtual void* execute(void*) = 0;
	bool isActive();
	void setActive(bool active);

};

