#pragma once
#include "State.h"
class ToLeftState :
	public State
{
public:
	ToLeftState(Robot* robot);
	void execute();
};

