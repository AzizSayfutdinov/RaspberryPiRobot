#pragma once
#include "State.h"
#include "Robot.h"

class IdleState: public State
{
private: 
	Robot* robot;
public: 
	IdleState(Robot* robot);

	void idle();
	void moveForward();
	void moveForwardLeft();
	void moveForwardRight();
	void turnLeft();
	void turnRight();
	void moveBackwards();
	void moveBackwardsRight();
	void moveBackwardsLeft();

	virtual void alignNorth();
	

};

