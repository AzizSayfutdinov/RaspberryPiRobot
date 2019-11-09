#pragma once
#include "Observer.h"

class ServerObserver: public Observer
{
private: 
	char input;

public: 

	void update();
	void update(int n);
};

