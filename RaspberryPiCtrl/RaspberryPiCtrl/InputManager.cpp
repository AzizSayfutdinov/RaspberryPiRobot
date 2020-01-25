#include "InputManager.h"

InputManager::InputManager()
{
}

char InputManager::getInput()
{
	// update();	// not needed if obserer pattern works
	// ((Server*)(subject))->receiveData();

	for (int i = 0; i < getSubjectList().size(); i++) {
		getSubjectList().at(i)->reveiveData();
	}

	// Just iterate through list and take some input
	// it is unlikely that the button and the clients will deliver inputs simultaneously
	
	return this->input;
}

void InputManager::update()
{
	// Goal: reveive input data from Button and Server

	// ((Server*)(subject))->receiveData();					// not needed if obserer pattern works
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
