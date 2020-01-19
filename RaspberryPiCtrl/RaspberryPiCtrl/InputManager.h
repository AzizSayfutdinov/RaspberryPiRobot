#pragma once
#include "Subject.h"
#include "Observer.h"
#include "Server.h"
#include "ServerObserver.h"

class InputManager: public Observer
{
private: 
	char input;
	Subject* subject;

public: 
	InputManager(Subject* observerSubject);
	char getInput();
	void update();
};

