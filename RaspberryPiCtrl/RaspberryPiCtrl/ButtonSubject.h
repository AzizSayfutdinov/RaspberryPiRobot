#pragma once
#include "Subject.h"

class ButtonSubject: public Subject
{
public: 
	void notify(int buttonNumber);
};

