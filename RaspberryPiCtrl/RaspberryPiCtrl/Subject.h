#pragma once
#include <vector>
#include "Observer.h"
#include <algorithm>

using namespace std;

class Subject
{
private: 
	vector<Observer*> observerList;	

public: 
	void attach(Observer* observer);		
	void detach(Observer* observer);		
	void notify();	
	vector<Observer*> getObserverList();

	
};

