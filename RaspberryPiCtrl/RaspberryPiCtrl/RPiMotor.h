#pragma once
#include "Motor.h"

// perspective at robot from above
#define MOTOR_RIGHT_POS 19
#define MOTOR_RIGHT_NEG 20
#define MOTOR_LEFT_POS 21
#define MOTOR_LEFT_NEG 26

class RPiMotor: public Motor
{
private: 
	int motorPinPos;
	int motorPinNeg;
	double power = 0;

public: 
	RPiMotor(int motorPinPos, int motorPinNeg);
	double getPower();
	void setPower(double power);
	static void resetAll();

};

