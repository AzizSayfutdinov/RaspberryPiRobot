#include "ButtonObserver.h"

void ButtonObserver::update(int buttonNumber)
{
	this->buttonNumber = buttonNumber;
}

void ButtonObserver::update()
{
}

char ButtonObserver::getButtonNumber()
{
	char c = static_cast<char> (buttonNumber);
	return c;
}
