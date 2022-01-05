#pragma once
#include "State.h"

class IdleState :
	public State
{
public: 
	IdleState(Handler* handler);
	void execute();
};

