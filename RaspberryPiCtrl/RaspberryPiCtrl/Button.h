#pragma once
#include <wiringPiI2C.h>
#include "IInput.h"

#define BUTTON_PIN 23
#define RASPI_ID 0x28
#define BUTTON_REG 3
#define REG_0 0

#define NO_BUTTON 0
#define BUTTON1 16
#define BUTTON2 32
#define BUTTON3 64
#define BUTTON4 128
#define BUTTON5 1
#define BUTTON6 2
#define BUTTON7 4
#define BUTTON8 8

// compiler returns error only if abstract method not implemented & you try to instantiate class

class Button: public IInput
{
private:
	int buttonPin;
	int I2CfdButton;

public:
	Button(int buttonPin);
	int buttonXpressed();	// returns which button (out of 8 buttons) is pressed
	char getInput();

};