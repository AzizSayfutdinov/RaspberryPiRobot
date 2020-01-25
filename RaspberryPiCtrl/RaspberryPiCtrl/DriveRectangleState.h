#pragma once
#include "State.h"
#include "Handler.h"

class DriveRectangleState :
	public State
{
public: 
	DriveRectangleState(Handler* handler);
	void execute();
};

