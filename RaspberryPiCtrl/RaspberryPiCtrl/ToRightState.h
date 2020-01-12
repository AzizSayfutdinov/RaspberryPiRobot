#pragma once
#include "State.h"
class ToRightState :
	public State
{
public:
	ToRightState(Robot* robot);
	int execute();
};

