#pragma once
#include "Observer.h"
#include "Server.h"	// versuche das loszuwerden
#include "Subject.h"

class InputManager: public Observer
{
private: 
	char input;
	Subject* subject;

public: 

	InputManager();
	InputManager(Subject* subject);
	char getInput();
	void update();
	void addSubject(Subject* subject);		// TODO: extend property to list of Subject*
};

