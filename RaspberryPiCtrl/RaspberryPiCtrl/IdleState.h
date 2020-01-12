#pragma once
#include "State.h"
class IdleState :
	public State
{
public: 
	IdleState(Robot* robot);
	int execute();
};

