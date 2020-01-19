#pragma once
#include "State.h"
#include "Robot.h"

class StateManager
{
private: 
	Robot* robot;
	State* currentState;

public: 
	StateManager(Robot* robot);
	State* updateCurrentState(char inputChar);
};

