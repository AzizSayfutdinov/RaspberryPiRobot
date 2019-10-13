#include "Button.h"
#include <wiringPi.h>

Button::Button(int buttonPin, int buttonNr)
{
	pinMode(buttonPin, INPUT);
	this->buttonPin = buttonPin;
	this->I2CfdButton = wiringPiI2CSetup(RASPI_ID);

}

int Button::buttonXpressed()
{
	int buttonValue = wiringPiI2CReadReg8(I2CfdButton, BUTTON_REG);

	switch (buttonValue)
	{
	case 1: 
		//
		break;
	case 2 :
		// 
		break;
	case 4: 

	case 8: 
		break; 
	default:
		break;
	}
}

