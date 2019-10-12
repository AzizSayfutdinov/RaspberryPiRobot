#pragma once
#include "Motor.h"

class SimMotor: public Motor
{
private:
	double power = 0;

public:
	SimMotor();
	double getPower();
	void setPower(double power);

};

