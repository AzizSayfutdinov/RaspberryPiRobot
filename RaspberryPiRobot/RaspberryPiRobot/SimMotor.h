#pragma once
class SimMotor
{
private:
	double power = 0;

public:
	SimMotor();
	double getPower();
	void setPower(double power);

};

