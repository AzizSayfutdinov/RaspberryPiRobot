#pragma once
#include <iostream>
#include <list>
#include "Observer.h"

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

