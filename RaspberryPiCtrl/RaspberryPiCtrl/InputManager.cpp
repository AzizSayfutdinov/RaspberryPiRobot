#include "InputManager.h"

InputManager::InputManager(){ }

InputManager::InputManager(Subject* subject)
{
	this->subject = subject;
}

char InputManager::getInput()
{
	((Server*)(subject))->receiveData();
	return this->input;
}

void InputManager::update()
{
	// Goal: reveive input data from Button and Server		// try to remove casting. Should also work it additional interface is added
	this->input = ((Server*)(subject))->getBuffer()[0];		// only first character -> later: send #states charachters

	// for debugging
	if (this->input == 'f') {
		char* value = ((Server*)(subject))->getBuffer();
		char values[100];
		for (int i = 0; i < 100; i++) {
			values[i] = ((Server*)(subject))->getBuffer()[i];
		}

		int a = 2;
	}
	((Server*)(subject))->clearBuffer();

}

void InputManager::addSubject(Subject* subject)
{
	this->subject = subject;
}
