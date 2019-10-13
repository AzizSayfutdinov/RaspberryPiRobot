#include "DifferentialDrive.h"

DifferentialDrive::DifferentialDrive(Motor* motorLeft, Motor* motorRight) {
	this->motorLeft = motorLeft;
	this->motorRight = motorRight;
}

void DifferentialDrive::moveForward() {
	// distance traveled = ticks * mmPerTick
	double power = 30;
	// follow a ramp with for loop up to 100%
	motorLeft->setPower(power);
	motorRight->setPower(power);

}

void DifferentialDrive::moveBackward()
{
	double power = 30;
	// follow a ramp with for loop up to 100%
	motorLeft->setPower(-power);
	motorRight->setPower(-power);
}

void DifferentialDrive::stop() {

	// follow a ramp with for loop down to 0%
	motorLeft->setPower(0);
	motorRight->setPower(0);

}

void DifferentialDrive::turnLeft() {
	// turning around a certain center point. Should be calculated
	int power = 50;
	motorLeft->setPower(power);
	
	// motorRight->setPower(-power);



}

void DifferentialDrive::turnRight() {
	int power = 50;
	motorRight->setPower(power);
	// motorLeft->setPower(-power);
}
