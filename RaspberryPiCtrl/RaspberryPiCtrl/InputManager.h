#pragma once
#include "Observer.h"
#include "Server.h"	// versuche das loszuwerden
#include "Subject.h"
#include "IInput.h"
#include <vector>

class InputManager : public Observer
{
private:
	char input;
	Subject* subject;
	vector<IInput*> inputObjects;

public:
	InputManager();
	InputManager(Subject* subject);
	char getInput();
	void update();
	void addInputObject(IInput* inputObject);
	vector<IInput*> getInputObjects();

};

