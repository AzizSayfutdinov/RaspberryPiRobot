#pragma once
#include "Odometry.h"


class RPiCompassEncoder
{
private: 
	Odometry* odometry;

public: 
	RPiCompassEncoder(Odometry* odometry);
	double getDirection();
};

