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
	this->power = power;

	if ((int)power == 0){	// motor does not turn off, of softPWMWrite(power = 0)
		digitalWrite(motorPinPos, LOW);
	}
	softPwmWrite(motorPinPos, (int)power);
	digitalWrite(motorPinNeg, LOW);

}
