#include "..\..\RaspberryPiCtrl\RaspberryPiCtrl\Subject.h"

void Subject::attach(Observer* observer)
{
	observerList.push_back(observer);
}

void Subject::detach(Observer* observer)
{
}
