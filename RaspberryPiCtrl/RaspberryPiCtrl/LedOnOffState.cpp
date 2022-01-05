#include "LedOnOffState.h"

bool LedOnOffState::currentMode = false;

LedOnOffState::LedOnOffState(Handler* handler)
{
	this->handler = handler;
	currentMode = !currentMode;
	setPeriodic(false);		// has to be executed only once within timeout in main

}

void LedOnOffState::execute()
{
	// what exactly is happening in the background? Is the encoder thread a source of interference? 
	// currentState = !currentState;
	if (currentMode) {
		digitalWrite(LED, HIGH);
	}
	else
	{
		digitalWrite(LED, LOW);
	}
}
