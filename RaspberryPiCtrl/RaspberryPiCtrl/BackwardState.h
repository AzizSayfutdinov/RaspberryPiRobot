#pragma once
#include "State.h"
class BackwardState :
	public State
{
public:
	BackwardState(Robot* robot);
	void* execute(void*);
};

