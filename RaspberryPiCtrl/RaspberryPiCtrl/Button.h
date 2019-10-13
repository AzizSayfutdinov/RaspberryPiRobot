#pragma once
#include <wiringPiI2C.h>

#define BUTTON1 23
#define RASPI_ID 0x28
#define BUTTON_REG 3

class Button
{
private: 
	int buttonPin;
	int I2CfdButton;
	int buttonNr;

public: 
	Button(int buttonPin, int buttonNr);
	int buttonXpressed();	// returns which button (out of 8 buttons) is pressed

};

