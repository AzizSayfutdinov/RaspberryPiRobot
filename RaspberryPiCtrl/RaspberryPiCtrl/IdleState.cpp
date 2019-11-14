#include "IdleState.h"
#include "MoveForwardState.h"
#include "MoveBackwardsState.h"
#include "MoveForwardRightState.h"
#include "MoveForwardLeftState.h"
#include "MoveBackwardsRightState.h"
#include "MoveBackwardsLeftState.h"
#include "TurnLeftState.h"
#include "TurnRightState.h"

// Explanation: 
// I am currently in IDLE State and the char for the corresponding actions below is received
// Upon reception the actions are performed and the state is changed if needed

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

void IdleState::moveForwardRight()
{
	robot->getDrive()->turnRight(turnRatio);
	MoveForwardRightState* mfrState = new MoveForwardRightState(robot);
	robot->setState(mfrState);
}

void IdleState::moveForwardLeft()
{
	robot->getDrive()->turnLeft(turnRatio);
	MoveForwardLeftState* mflState = new MoveForwardLeftState(robot);
	robot->setState(mflState);

}

void IdleState::moveBackwards()
{
	robot->getDrive()->moveBackward();
	MoveBackwardsState* mbState = new MoveBackwardsState(robot);
	robot->setState(mbState);
}

void IdleState::moveBackwardsRight()
{
	robot->getDrive()->turnLeft(-turnRatio);
	MoveBackwardsRightState* mbrState = new MoveBackwardsRightState(robot);
	robot->setState(mbrState);
}

void IdleState::moveBackwardsLeft()
{
	robot->getDrive()->turnRight(-turnRatio);
	MoveBackwardsLeftState* mblState = new MoveBackwardsLeftState(robot);
	robot->setState(mblState);
}

void IdleState::alignNorth()
{
}

void IdleState::turnLeft() 
{
	robot->getDrive()->turnLeft();
	TurnLeftState* tlState = new TurnLeftState(robot);
	robot->setState(tlState);
}

void IdleState::turnRight()
{
	robot->getDrive()->turnRight();
	TurnRightState* trState = new TurnRightState(robot);
	robot->setState(trState);
}

