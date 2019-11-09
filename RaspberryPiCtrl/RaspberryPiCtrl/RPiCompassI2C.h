#pragma once
#include "Compass.h"

#define I2C_ADDRESS 0x60

class RPiCompassI2C: public Compass
{
private: 
	int I2CfdCompass;

public:
	RPiCompassI2C(int I2C_id);		// id = I2C bus adress
	double getDirection8bit();			// return direction in degrees from north
	double getDirection();
};

