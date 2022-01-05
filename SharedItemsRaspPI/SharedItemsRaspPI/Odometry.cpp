#include "Odometry.h"
#include "Encoder.h"


Odometry::Odometry(Encoder* encoderLeft, Encoder* encoderRight, Compass* compass)
{
	this->encoderLeft = encoderLeft;
	this->encoderRight = encoderRight;
	this->compass = compass;
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
	return compass->getDirection();
}

void Odometry::reset() {
	ticksLeft = 0;
	ticksRight = 0;

}

double Odometry::ticksToAngle(long ticks) {
	// exactly the x I calculated: rotational distance of one wheel with the 
	// rotational center point at c
	// see documentation: TODO

	return 1;
}


void Odometry::alignNorth(DifferentialDrive* drive) {
	while (compass->getDirection() < 359.0 && compass->getDirection() > 1.0) {
		drive->turnLeft(0.8);
	}
}
