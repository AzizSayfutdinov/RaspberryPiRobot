#pragma once
#include "Compass.h"

class RPiCompassI2C: public Compass
{
private: 
	int I2CfdCompass;

public:
	RPiCompassI2C(int I2C_id);		// id = I2C bus adress
	double getDirection();			// return direction in degrees from north
};

