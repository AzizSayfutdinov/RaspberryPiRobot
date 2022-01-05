#pragma once
#include "State.h"
class ToLeftState :
	public State
{
public:
	ToLeftState(Handler* handler);
	void execute();
};

