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
		return new ForwardState(robot);
		break;
	case 'b':
		// robot->getDrive()->moveBackward();
		return new BackwardState(robot);
		break;
	case 's':
		// robot->getDrive()->stop();
		return new IdleState(robot);
		break;
	case 'r':
		// robot->getDrive()->turnRight();
		return new ToRightState(robot);
		break;
	case 'l':
		// robot->getDrive()->turnLeft();
		return new ToLeftState(robot);
		break;
	default:
		return new IdleState(robot);
		break;
	}
}


