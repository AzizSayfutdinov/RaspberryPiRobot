#pragma once
#include <vector>
#include "Observer.h"
#include <algorithm>

class Subject
{
private: 
	std::vector<Observer*> observerList;	

public: 
	void attach(Observer* observer);		
	void detach(Observer* observer);		
	void notify();	
};

