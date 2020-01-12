#pragma once
#include "State.h"
class ToLeftState :
	public State
{
public:
	ToLeftState(Robot* robot);
	int execute();
};

