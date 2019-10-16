#pragma once
#include "Observer.h"
#include <iostream>
#include <list>

using namespace std;

class Subject
{
public: 
	virtual ~Subject();

	virtual void attach(Observer* observer);
	virtual void detach(Observer* observer);
	virtual void notify();

protected: 
	Subject();

private: 
	list<Observer*>* observers;
};

