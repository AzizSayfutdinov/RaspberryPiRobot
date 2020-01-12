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
	((Server*)(subject))->receiveData();
	this->input = ((Server*)(subject))->getBuffer()[0];		// only first character -> later: send #states charachters
}

// TODO: 
// InputManager should return the corresponding State