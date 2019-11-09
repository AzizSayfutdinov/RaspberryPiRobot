#pragma once
#include "IInput.h"
#include "Subject.h"
#include "Button.h"
#include "ButtonObserver.h"
#include "ServerObserver.h"
#include <vector>

#define INDEX_BUTTON1
#define INDEX_BUTTON2
#define INDEX_BUTTON3
#define INDEX_BUTTON4
#define INDEX_SERVER

// receives input data from button or client

class InputManager
{
private: 
	char* input;
	std::vector<Observer*> observerList;
	std::vector<Subject*> inputList;

	void addObserver(Observer* observer, int atIndex);
	void addInput(Subject* input, int atIndex);

public: 
	char getInput();
	void addInputSubject(Subject* input, Observer* observer, int atIndex);
};

