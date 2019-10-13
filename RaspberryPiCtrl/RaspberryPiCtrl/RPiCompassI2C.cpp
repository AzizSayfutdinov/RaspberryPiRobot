#include "RPiCompassI2C.h"
#include <wiringPiI2C.h>

#define COMPASS_8REG 1		// register with 8bit values 

RPiCompassI2C::RPiCompassI2C(int I2C_id)
{
	this->I2CfdCompass = wiringPiI2CSetup(I2C_id);
}

double RPiCompassI2C::getDirection()
{
	// return direction in degrees from north
	int regValue = wiringPiI2CReadReg8(this->I2CfdCompass, COMPASS_8REG);
	double degrees = (360.0 / 256.0) * regValue;
	return degrees;
}
