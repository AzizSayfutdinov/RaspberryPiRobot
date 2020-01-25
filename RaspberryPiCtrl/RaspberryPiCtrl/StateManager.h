#pragma once
#include "State.h"
#include "Handler.h"

class StateManager
{
private: 
	Handler* handler;
	State* currentState;

public: 
	StateManager(Handler* handler);
	State* updateCurrentState(char inputChar);
};

