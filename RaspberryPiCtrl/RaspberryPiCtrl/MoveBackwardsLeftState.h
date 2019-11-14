#pragma once
#include "State.h"
#include "Robot.h"

class MoveBackwardsLeftState :
	public State
{
private:
	Robot* robot;

public:
	MoveBackwardsLeftState(Robot* robot);

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

