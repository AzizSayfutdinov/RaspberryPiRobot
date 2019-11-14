#pragma once
#include "State.h"
#include "Robot.h"

class MoveForwardLeftState :
	public State
{
private:
	Robot* robot;

public:
	MoveForwardLeftState(Robot* robot);

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
