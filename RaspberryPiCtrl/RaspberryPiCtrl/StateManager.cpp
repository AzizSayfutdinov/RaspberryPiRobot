#include "StateManager.h"
#include "IdleState.h"
#include "ForwardState.h"
#include "BackwardState.h"
#include "ToLeftState.h"
#include "ToRightState.h"
#include "AlignNorthState.h"

StateManager::StateManager(Handler* handler)
{
	this->handler = handler;
	// currentState = new IdleState(this->handler);
	// currentStateSet: initialize it with all possible states
	// let thread run on those which are active
}

State* StateManager::updateCurrentState(char inputChar)
{
	switch (inputChar)
	{
	case 'f':
		return new ForwardState(handler);
		break;
	case 'b':
		return new BackwardState(handler);
		break;
	case 's':
		return new IdleState(handler);
		break;
	case 'r':
		return new ToRightState(handler);
		break;
	case 'l':
		return new ToLeftState(handler);
		break;
	case 'a':
		return new AlignNorthState(handler);
		break;
	default:
		return new IdleState(handler);
		break;
	}
}


