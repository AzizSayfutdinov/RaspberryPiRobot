#include "DriveRectangleState.h"
#include "AlignNorthState.h"

DriveRectangleState::DriveRectangleState(Handler* handler)
{
	this->handler = handler;
}

void DriveRectangleState::execute()
{
	// scalable for different polygon shapes
	int numberOfEdges = 4;
	double cornerAngle = 360 / numberOfEdges;	// in deg
	int edgeSize = 300;	// in mm

	for (int i = 0; i < numberOfEdges; i++) {
		// set size of rectangle edge
		double lastDistance = handler->odometry->getDistance();
		double traveledDistance = 0;

		while (traveledDistance < edgeSize) {
			handler->drive->moveForward();
			double currentDistance = handler->odometry->getDistance();
			traveledDistance = currentDistance - lastDistance;
		}

		// turning by 90°
		// turning right increases angle
		double lastAngle = handler->odometry->getHeading();
		double turnedAngle = 0;

		while (turnedAngle < cornerAngle) {
			handler->drive->turnRight();
			double currentAngle = handler->odometry->getHeading();
			turnedAngle = currentAngle - lastAngle;
			if (turnedAngle < 0) {
				turnedAngle = turnedAngle + 360;
			}
		}
		handler->drive->stop();

	}
}
