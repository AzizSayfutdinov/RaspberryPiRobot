#include "StateManager.h"
#include "IdleState.h"
#include "ForwardState.h"
#include "BackwardState.h"
#include "ToLeftState.h"
#include "ToRightState.h"

StateManager::StateManager(Robot* robot)
{
	this->robot = robot;
	currentState = new IdleState(this->robot);
	// currentStateSet: initialize it with all possible states
	// let thread run on those which are active
}

State* StateManager::updateCurrentState(char inputChar)
{
	switch (inputChar)
	{
	case 'f':
		// robot->getDrive()->moveForward();
		return currentState = new ForwardState(robot);
		break;
	case 'b':
		// robot->getDrive()->moveBackward();
		return currentState = new BackwardState(robot);
		break;
	case 's':
		// robot->getDrive()->stop();
		return currentState = new IdleState(robot);
		break;
	case 'r':
		// robot->getDrive()->turnRight();
		return currentState = new ToRightState(robot);
		break;
	case 'l':
		// robot->getDrive()->turnLeft();
		return currentState = new ToLeftState(robot);
		break;
	default:
		return currentState = new IdleState(robot);
		break;
	}
}


