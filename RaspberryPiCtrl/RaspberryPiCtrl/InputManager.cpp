#include "InputManager.h"

void InputManager::addObserver(Observer* observer, int atIndex)
{
	observerList.insert(observerList.begin() + atIndex, observer);
}

void InputManager::addInput(Subject* input, int atIndex)
{
	inputList.insert(inputList.begin() + atIndex, input);
}

char InputManager::getInput()
{
	// nur einen Button ansprechen reicht: 
	((Button*)inputList[INDEX_BUTTON1 + 0])->buttonXpressed();

	char c = ((ButtonObserver*)observerList[INDEX_BUTTON1 + 0])->getButtonNumber();		// nimmt macro nicht an: expression expected
	if (c == '0') {
		char c = ((ButtonObserver*)observerList[INDEX_BUTTON2 + 0])->getButtonNumber();
	}
	if (c == '0') {
		char c = ((ButtonObserver*)observerList[INDEX_BUTTON3 + 0])->getButtonNumber();
	}
	if (c == '0') {
		char c = ((ButtonObserver*)observerList[INDEX_BUTTON4 + 0])->getButtonNumber();
	}
	return c;
}

void InputManager::addInputSubject(Subject* input, Observer* observer, int atIndex)
{
	addObserver(observer, atIndex);
	addInput(input, atIndex);
}
