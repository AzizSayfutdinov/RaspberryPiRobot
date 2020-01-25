#pragma once
#include "State.h"
#include "Handler.h"
#include "wiringPi.h"

#define LED 17

class LedOnOffState :
	public State
{
public: 
	static bool currentState;
	LedOnOffState(Handler* handler);
	void execute();
};

