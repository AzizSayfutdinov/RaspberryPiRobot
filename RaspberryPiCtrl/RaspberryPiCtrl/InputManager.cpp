#include "InputManager.h"

InputManager::InputManager(Subject* observerSubject)
{
	this->subject = observerSubject;
}

char InputManager::getInput()
{
	update();
	return this->input;
}

void InputManager::update()
{
	// Goal: reveive input data from Button and Server
	((Server*)(subject))->receiveData();
	this->input = ((Server*)(subject))->getBuffer()[0];		// only first character -> later: send #states charachters
	((Server*)(subject))->clearBuffer();
}
