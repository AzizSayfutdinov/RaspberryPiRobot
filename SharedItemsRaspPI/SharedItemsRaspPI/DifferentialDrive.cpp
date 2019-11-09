#include "DifferentialDrive.h"
#include <iostream>


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
	// additional input: degrees in positive rotational direction
	// use odometry class to access encoder and get the values for 
	// the left and right encoder
	// -> calculate needed tick-difference between each encoder
	// for the needed angle 
	// use the difference as stop condition for the while loop
	// and stop the motor
	int degrees = 0;

	int power = 50;
	motorLeft->setPower(power);
	motorRight->setPower(-power);
}

void DifferentialDrive::turnLeft(int power) {
	motorLeft->setPower(power);
	motorRight->setPower(-power);
}

void DifferentialDrive::turnRight() {
	int power = 50;
	motorRight->setPower(power);
	motorLeft->setPower(-power);
}
