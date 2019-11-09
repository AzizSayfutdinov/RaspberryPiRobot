#pragma once
#include "Observer.h"
#include "Subject.h"

class ButtonObserver: public Observer
{
private: 
	int buttonNumber;

public: 
	void update(int buttonNumber);
	void update();
	char getButtonNumber();
};

