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

	if (power < -100 && power > 100) {
		// throw exception
	}

	this->power = power;

	if ((int)power == 0){	

		softPwmWrite(motorPinPos, 0);
		softPwmWrite(motorPinNeg, 0);
	}
	if (power > 0) {	// motor in forward mode
		softPwmWrite(motorPinNeg, 0);
		softPwmWrite(motorPinPos, (int)power);

	}
	else				// motor in forward mode
	{
		softPwmWrite(motorPinPos, 0);
		softPwmWrite(motorPinNeg, -(int)power);		// set sign to positive
	}


}

void RPiMotor::resetAll()
{
	softPwmWrite(MOTOR_RIGHT_POS, LOW);
	softPwmWrite(MOTOR_RIGHT_NEG, LOW);
	softPwmWrite(MOTOR_LEFT_POS, LOW);
	softPwmWrite(MOTOR_LEFT_NEG, LOW);
}