#include "StateManager.h"
#include "IdleState.h"
#include "ForwardState.h"
#include "BackwardState.h"
#include "ToLeftState.h"
#include "ToRightState.h"

StateManager::StateManager(Handler* handler)
{
	this->handler = handler;
	currentState = new IdleState(this->handler);
	// currentStateSet: initialize it with all possible states
	// let thread run on those which are active
}

State* StateManager::updateCurrentState(char inputChar)
{
	switch (inputChar)
	{
	case 'f':
		// robot->getDrive()->moveForward();
		return currentState = new ForwardState(handler);
		break;
	case 'b':
		// robot->getDrive()->moveBackward();
		return currentState = new BackwardState(handler);
		break;
	case 's':
		// robot->getDrive()->stop();
		return currentState = new IdleState(handler);
		break;
	case 'r':
		// robot->getDrive()->turnRight();
		return currentState = new ToRightState(handler);
		break;
	case 'l':
		// robot->getDrive()->turnLeft();
		return currentState = new ToLeftState(handler);
		break;
	default:
		return currentState = new IdleState(handler);
		break;
	}
}


