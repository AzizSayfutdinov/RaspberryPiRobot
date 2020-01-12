#pragma once
#include "Robot.h"

class State
{
protected: 
	bool active = false;		// default
	Robot* robot;

public: 
	virtual int execute() = 0;
	bool isActive();
	void setActive(bool active);

};

