#include "Odometry.h"

Odometry::Odometry(Encoder* encoderLeft, Encoder* encoderRight) {
	this->encoderLeft = encoderLeft;
	this->encoderRight = encoderRight;
}

double Odometry::getDistance() {
	// ticks * mmPerTick
	// distance traveled bx center point
	
	// use small time differences to calculate distance in a curve
	// current - previousTicks = tickDifference
	// resoluation too bad
	
	return encoderLeft->getTicks() * mmPerTick;
}

double Odometry::getHeading() {
	// degrees from north in positive rotational direction


	return 1;
}

void Odometry::reset() {
	// reset?
	ticksLeft = 0;
	ticksRight = 0;

}

double Odometry::ticksToAngle(long ticks) {
	// exactly the x I calculated: rotational distance of one wheel with the 
	// rotational center point at c
	// see documentation


	return 1;
}

