#pragma once
#include "State.h"
#include "Robot.h"

class MoveForwardRightState :
	public State
{
private: 
	Robot* robot;

public: 
	MoveForwardRightState(Robot* robot);

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

