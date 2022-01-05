#pragma once
#include "Motor.h"

class DifferentialDrive
{
private: 
	static DifferentialDrive* instance;
	Motor* motorLeft;
	Motor* motorRight;
	double maxPower = 100;	// nur für drive ist power wichtig. Robot muss es nicht kennen. Default = 100%. 
							// Get value from slider (init process needed to know the slider value)
	// singleton implementation
	DifferentialDrive(Motor* motorLeft, Motor* motorRight);

public: 
	
	void moveForward();
	void moveBackward();
	void stop();
	void turnLeft();
	void turnLeft(double ratio);
	void turnRight();
	void turnRight(double ratio);
	void setMaxPower(double maxPower);
	double getMaxPower();

	// singleton immplementation
	static DifferentialDrive* getInstance(Motor* motorLeft, Motor* motorRight);
	
};

