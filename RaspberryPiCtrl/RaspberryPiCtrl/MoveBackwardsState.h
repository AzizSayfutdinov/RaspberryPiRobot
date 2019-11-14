#pragma once
#include "State.h"
#include "Robot.h"

class MoveBackwardsState :
	public State
{
private: 
	Robot* robot;

public: 
	MoveBackwardsState(Robot* robot);

	void idle();
	void moveForward();
	void moveForwardLeft();
	void moveForwardRight();
	void turnLeft();
	void turnRight();
	void moveBackwards();
	void moveBackwardsRight();
	void moveBackwardsLeft();
	void alignNorth();
};
