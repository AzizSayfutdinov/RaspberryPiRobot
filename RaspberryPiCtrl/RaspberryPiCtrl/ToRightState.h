#pragma once
#include "State.h"
class ToRightState :
	public State
{
public:
	ToRightState(Handler* handler);
	void execute();
};

