#pragma once
#include "Observer.h"
#include "Server.h"	// versuche das loszuwerden

class InputManager: public Observer
{
private: 
	char input;

public: 
	InputManager();
	char getInput();
	void update();
};

