#pragma once
#include "Robot.h"

class State
{
protected:
	bool active = true;		// default
	Robot* robot;

public:
	virtual void execute() = 0;
	bool isActive();
	void setActive(bool active);

};

