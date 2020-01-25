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
