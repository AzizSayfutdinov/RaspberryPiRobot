#include "RPiMotor.h"
#include <wiringPi.h>
#include <softPwm.h>

RPiMotor::RPiMotor(int motorPinPos, int motorPinNeg) {
	this->motorPinNeg = motorPinNeg;
	this->motorPinPos = motorPinPos;

}

double RPiMotor::getPower() {
	return power;
}

void RPiMotor::setPower(double power) {

	// PROBLEM
	// At the moment, the outputs have to be set twice in order to start
	// TODO: Include the encoder as a property to the motor and check
	// whether the motor actually works

	// temporary fix: set outputs twice

	if (power < -100 && power > 100) {
		// throw exception
	}

	this->power = power;

	if ((int)power == 0){	

		for (int i = 0; i < 2; i++)
		{
			softPwmWrite(motorPinPos, 0);
			softPwmWrite(motorPinNeg, 0);
			// digitalWrite(motorPinPos, LOW);		// digital sets max to 0. Basically turning PIN off
			// digitalWrite(motorPinNeg, LOW);
		}
	}
	if (power > 0) {	// motor in forward mode
		
		for (int i = 0; i < 2; i++)
		{
			// softPwmWrite(motorPinNeg, 0);
			softPwmWrite(motorPinPos, (int)power);
		}
	}
	else				// motor in forward mode
	{
		for (int i = 0; i < 2; i++)
		{
			// softPwmWrite(motorPinPos, 0);
			softPwmWrite(motorPinNeg, -(int)power);		// set sign to positive
		}
	}
}

void RPiMotor::resetAll()
{
	softPwmWrite(MOTOR_RIGHT_POS, LOW);
	softPwmWrite(MOTOR_RIGHT_NEG, LOW);
	softPwmWrite(MOTOR_LEFT_POS, LOW);
	softPwmWrite(MOTOR_LEFT_NEG, LOW);
}
