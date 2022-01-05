#pragma once
#include "State.h"

class ForwardState :
	public State
{
public:
	ForwardState(Handler* handler);
	void execute();
};

