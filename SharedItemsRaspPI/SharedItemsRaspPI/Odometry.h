#pragma once
#include "Encoder.h"

class Odometry
{
private:
	Encoder* encoderLeft;
	Encoder* encoderRight;
	long ticksLeft = 0;
	long ticksRight = 0;
	const double mmPerTick = 207.0 / 20.0;
	const double PI = 3.141592654;
	const double wheelDistance = 131;

public:
	Odometry(Encoder* encoderLeft, Encoder* encoderRight);
	double getDistance();
	double getHeading();		// orientation? 
	void reset();
	double ticksToAngle(long ticks);
	
};

