#include "InputManager.h"

InputManager::InputManager(){ }

InputManager::InputManager(Subject* subject)
{
	this->subject = subject;
}

char InputManager::getInput()
{
	((Server*)(subject))->receiveData();	// stuck this place

	for (int i = 0; i < inputObjects.size(); i++) {
		char temp = inputObjects.at(i)->getInput();
		if (temp != '\0') {
			input = temp;
		}
	}

	// timing problem
	// if the server is getting input first, it waits for data: use thread to split data aquisition from button and client
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

void InputManager::addInputObject(IInput* inputObject)
{
	inputObjects.push_back(inputObject);
}

vector<IInput*> InputManager::getInputObjects()
{
	return inputObjects;
}
