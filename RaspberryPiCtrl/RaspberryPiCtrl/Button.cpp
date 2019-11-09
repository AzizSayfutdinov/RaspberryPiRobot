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
	int buttonPressed = 0;

	switch (buttonValue)
	{
	case NO_BUTTON: 
		buttonPressed = 0;	// no button was pressed
		break;

	case BUTTON1: 
		buttonPressed = 1;
		break;

	case BUTTON2:
		buttonPressed = 2;
		break;

	case BUTTON3: 
		buttonPressed = 3;
		break;

	case BUTTON4: 
		buttonPressed = 4;
		break;

	case BUTTON5: 
		buttonPressed = 5;
		break;

	case BUTTON6: 
		buttonPressed = 6;
		break;

	case BUTTON7:
		buttonPressed = 7;
		break;

	case BUTTON8: 
		buttonPressed = 8;
		break; 
	default:
		// include proper exception/notice
		break;
	}
	return 1;
}

