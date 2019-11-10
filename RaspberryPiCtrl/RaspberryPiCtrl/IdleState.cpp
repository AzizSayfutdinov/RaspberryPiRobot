#include "IdleState.h"
#include "MoveForwardState.h"

IdleState::IdleState(Robot* robot)
{
	this->robot = robot;
}

void IdleState::idle()
{
	// nothing to do, the state stays the same
}

void IdleState::moveForward()
{
	robot->getDrive()->moveForward();
	MoveForwardState* mfState = new MoveForwardState(robot);
	robot->setState(mfState);
}
