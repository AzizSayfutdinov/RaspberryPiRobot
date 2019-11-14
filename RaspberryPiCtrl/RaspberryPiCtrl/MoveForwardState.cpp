#include "MoveForwardState.h"
#include "IdleState.h"
#include "MoveBackwardsState.h"
#include "MoveForwardRightState.h"
#include "MoveForwardLeftState.h"
#include "MoveBackwardsRightState.h"
#include "MoveBackwardsLeftState.h"
#include "TurnLeftState.h"
#include "TurnRightState.h"

MoveForwardState::MoveForwardState(Robot* robot)
{
	this->robot = robot;
}

void MoveForwardState::idle()
{
	robot->getDrive()->stop();
	IdleState* idleState = new IdleState(robot);
	robot->setState(idleState);
}

void MoveForwardState::moveForward()
{
	// nothing to do, the state stays the same
}

void MoveForwardState::moveForwardRight()
{
	robot->getDrive()->turnRight(turnRatio);
	MoveForwardRightState* mfrState = new MoveForwardRightState(robot);
	robot->setState(mfrState);
}

void MoveForwardState::moveForwardLeft()
{
	robot->getDrive()->turnLeft(turnRatio);
	MoveForwardLeftState* mflState = new MoveForwardLeftState(robot);
	robot->setState(mflState);

}

void MoveForwardState::moveBackwards()
{
	robot->getDrive()->moveBackward();
	MoveBackwardsState* mbState = new MoveBackwardsState(robot);
	robot->setState(mbState);
}

void MoveForwardState::moveBackwardsRight()
{
	robot->getDrive()->turnLeft(-turnRatio);
	MoveBackwardsRightState* mbrState = new MoveBackwardsRightState(robot);
	robot->setState(mbrState);
}

void MoveForwardState::moveBackwardsLeft()
{
	robot->getDrive()->turnRight(-turnRatio);
	MoveBackwardsLeftState* mblState = new MoveBackwardsLeftState(robot);
	robot->setState(mblState);
}

void MoveForwardState::turnLeft()
{
	robot->getDrive()->turnLeft();
	TurnLeftState* tlState = new TurnLeftState(robot);
	robot->setState(tlState);
}

void MoveForwardState::turnRight()
{
	robot->getDrive()->turnRight();
	TurnRightState* trState = new TurnRightState(robot);
	robot->setState(trState);
}

void MoveForwardState::alignNorth()
{
	// TODO
}