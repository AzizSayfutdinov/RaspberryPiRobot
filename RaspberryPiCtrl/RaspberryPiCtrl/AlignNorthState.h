#pragma once
#include "State.h"
#include "Handler.h"

class AlignNorthState :
	public State
{
public: 
	AlignNorthState(Handler* handler);
	void execute();
};

