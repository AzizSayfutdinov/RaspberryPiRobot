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
private: 
	RPiMotor* motorRight;  
	RPiMotor* motorLeft; 
	DifferentialDrive* drive;

	RPiEncoder* encoderRight;
	RPiEncoder* encoderLeft; 
	Odometry* odometry;  
	RPiCompassI2C* compass;
	Server* server;
	ServerObserver* serverObserver;
	State* currentState;
	Handler* handler;
	StateManager* sm;
	InputManager* im;


public: 
	Robot();
	Server* getServer();
	DifferentialDrive* getDrive();
	Odometry* getOdometry();
	State* getCurrentState();
	void setCurrentState(State* state);
	StateManager* getStateManager();
	InputManager* getInputManager();

};

