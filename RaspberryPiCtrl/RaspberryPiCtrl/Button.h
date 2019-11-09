#pragma once
#include <wiringPiI2C.h>
#include "IInput.h"
#include "Subject.h"

#define BUTTON_PIN 23
#define RASPI_ID 0x28
#define BUTTON_REG 3

#define NO_BUTTON 0
#define BUTTON1 16
#define BUTTON2 32
#define BUTTON3 64
#define BUTTON4 128
#define BUTTON5 1
#define BUTTON6 2
#define BUTTON7 4
#define BUTTON8 8

class Button: public IInput, public Subject
{
private: 
	int buttonPin;
	int I2CfdButton;
	int buttonNr;

public: 
	Button(int buttonPin, int buttonNr);
	int buttonXpressed();	// returns which button (out of 8 buttons) is pressed
	char getInput();
	void notify(int buttonNr);

};

