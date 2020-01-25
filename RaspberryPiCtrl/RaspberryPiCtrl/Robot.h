#pragma once
#include "DifferentialDrive.h"
#include "RPiMotor.h"
#include "RPiEncoder.h"
#include "RPiCompassI2C.h"
#include "Odometry.h"
#include "Server.h"
#include "ServerObserver.h"
#include "State.h"
#include "StateManager.h"
#include "Handler.h"
#include "InputManager.h"

class Robot
{

	static Robot* instance;
private: 
	RPiMotor* motorRight;  
	RPiMotor* motorLeft; 
	DifferentialDrive* drive;
	RPiEncoder* encoderRight;
	RPiEncoder* encoderLeft; 
	Odometry* odometry;  
	RPiCompassI2C* compass;
	Server* server;
	State* currentState;
	Handler* handler;
	StateManager* sm;
	InputManager* im;

	// singleton implementation
	Robot();	// constructor private to prevent contructor calls


public: 
	Server* getServer();
	DifferentialDrive* getDrive();
	Odometry* getOdometry();
	State* getCurrentState();
	void setCurrentState(State* state);
	StateManager* getStateManager();
	InputManager* getInputManager();

	// singleton implementation
	static Robot* getInstance();

};

