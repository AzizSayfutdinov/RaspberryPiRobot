#include "Subject.h"

void Subject::attach(Observer* observer)
{
	observerList.push_back(observer);
}

void Subject::detach(Observer* observer)
{
	observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end());
}


void Subject::notify()
{
	for (int i = 0; i < observerList.size(); i++) {
		observerList[i]->update();
	}
}

std::vector<Observer*>* Subject::getObserverList()
{
	return &observerList;
}
