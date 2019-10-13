#pragma once
#include "Odometry.h"
#include "Compass.h"

class RPiCompassEncoder: public Compass
{
private: 
	Odometry* odometry;

public: 
	RPiCompassEncoder(Odometry* odometry);
	double getDirection();
};

