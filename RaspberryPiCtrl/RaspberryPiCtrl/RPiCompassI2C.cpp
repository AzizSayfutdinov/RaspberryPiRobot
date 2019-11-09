#include "RPiCompassI2C.h"
#include <wiringPiI2C.h>

#define COMPASS_8REG 1		// register with 8bit values 
#define COMPASS_16REG_HIGHBITS 2
#define COMPASS_16REG_LOWBITS 3

RPiCompassI2C::RPiCompassI2C(int I2C_id) 
{
	this->I2CfdCompass = wiringPiI2CSetup(I2C_id);
}

double RPiCompassI2C::getDirection()
{

	// 16 bit value
	int regHighBits = wiringPiI2CReadReg8(this->I2CfdCompass, COMPASS_16REG_HIGHBITS);
	int regLowBits = wiringPiI2CReadReg8(this->I2CfdCompass, COMPASS_16REG_LOWBITS);

	int result = regHighBits << 8;
	int temp = regLowBits + result;
	double degrees = temp / 10.0;
	return degrees;
}

double RPiCompassI2C::getDirection8bit()
{
	// return direction in degrees from north
	int regValue = wiringPiI2CReadReg8(this->I2CfdCompass, COMPASS_8REG);
	double degrees = (360.0 / 256.0) * regValue;

	return degrees;
}
