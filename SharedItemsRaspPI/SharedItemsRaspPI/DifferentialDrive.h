#pragma once
#include "Motor.h"

class DifferentialDrive
{
private: 
	Motor* motorLeft;
	Motor* motorRight;

public: 
	DifferentialDrive(Motor* motorLeft, Motor* motorRight);
	void moveForward();
	void stop();
	void turnLeft();
	void turnRight();
};

