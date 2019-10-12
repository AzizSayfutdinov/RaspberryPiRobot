#include "DifferentialDrive.h"


DifferentialDrive::DifferentialDrive(Motor* motorLeft, Motor* motorRight) {
	this->motorLeft = motorLeft;
	this->motorRight = motorRight;
}

void DifferentialDrive::moveForward() {
	// distance traveled = ticks * mmPerTick
	int power = 50;
	motorLeft->setPower(power);
	motorRight->setPower(power);

}

void DifferentialDrive::stop() {

}

void DifferentialDrive::turnLeft() {

}

void DifferentialDrive::turnRight() {

}
