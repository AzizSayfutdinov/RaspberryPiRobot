#pragma once

// Interface defining the transition functions
class State
{
public: 
	// Transitions with timeout Timer
	virtual void idle() = 0;
	virtual void moveForward() = 0;
	virtual void moveForwardLeft() = 0;
	virtual void moveForwardRight() = 0;
	virtual void turnLeft() = 0;
	virtual void turnRight() = 0;
	virtual void moveBackwards() = 0;
	virtual void moveBackwardsRight() = 0;
	virtual void moveBackwardsLeft() = 0;

	// Transition which are performed only once if called
	virtual void alignNorth() = 0;

};

