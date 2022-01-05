#pragma once
#include "State.h"

class BackwardState :
	public State
{
public:
	BackwardState(Handler* handler);
	void execute();
};

