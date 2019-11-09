#pragma once
#include "Observer.h"

class ServerObserver: public Observer
{
public: 
	void update();
	void update(int n);
};

