#pragma once
#include "State.h"
class ForwardState :
	public State
{
public:
	ForwardState(Robot* robot);
	void* execute(void*);
};

