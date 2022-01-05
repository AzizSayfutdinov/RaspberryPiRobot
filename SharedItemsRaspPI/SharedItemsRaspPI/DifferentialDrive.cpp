#include "DifferentialDrive.h"
#include <iostream>
#include "RobotExceptions.h"

DifferentialDrive::DifferentialDrive(Motor* motorLeft, Motor* motorRight) {
	this->motorLeft = motorLeft;
	this->motorRight = motorRight;
}

void DifferentialDrive::moveForward() {

	try
	{
		motorLeft->setPower(maxPower);
		motorRight->setPower(maxPower);
	}
	catch (OutOfBoundariesException& e)
	{
		std::cerr << e.what() << endl;		// not functional yet ... 
	}

}

void DifferentialDrive::moveBackward()
{
	motorLeft->setPower(-maxPower);
	motorRight->setPower(-maxPower);
}

void DifferentialDrive::stop() {

	// follow a ramp with for loop down to 0%
	motorLeft->setPower(0);
	motorRight->setPower(0);

}

void DifferentialDrive::turnLeft() {
	motorLeft->setPower(-maxPower);
	motorRight->setPower(maxPower);
}

void DifferentialDrive::turnLeft(double ratio) {
	motorLeft->setPower(-ratio*maxPower);
	motorRight->setPower(ratio*maxPower);
}

void DifferentialDrive::turnRight() {
	motorRight->setPower(-maxPower);
	motorLeft->setPower(maxPower);
}

void DifferentialDrive::turnRight(double ratio)
{
	motorLeft->setPower(ratio*maxPower);
	motorRight->setPower(-ratio*maxPower);
}

void DifferentialDrive::setMaxPower(double maxPower)
{
	this->maxPower = maxPower;
}

double DifferentialDrive::getMaxPower()
{
	return maxPower;
}

DifferentialDrive* DifferentialDrive::getInstance(Motor* motorLeft, Motor* motorRight)
{
	if (instance == NULL) {
		return new DifferentialDrive(motorLeft, motorRight);
	}
}
