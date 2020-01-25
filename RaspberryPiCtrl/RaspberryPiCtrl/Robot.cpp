#include "Robot.h"

Robot::Robot()
{
	Robot::motorRight = new RPiMotor(MOTOR_RIGHT_POS, MOTOR_RIGHT_NEG);
	Robot::motorLeft = new RPiMotor(MOTOR_LEFT_POS, MOTOR_LEFT_NEG);
	Robot::drive = new DifferentialDrive(motorLeft, motorRight);		// TODO: use singleton class

	Robot::encoderRight = new RPiEncoder(ENCODER_RIGHT);
	Robot::encoderLeft = new RPiEncoder(ENCODER_LEFT);
	Robot::compass = new RPiCompassI2C(I2C_ADDRESS);
	Robot::odometry = new Odometry(encoderLeft, encoderRight, compass);		// TODO: use singleton class
	
	Robot::server = new Server();
	Robot::serverObserver = new ServerObserver();
	server->attach(serverObserver);

	handler = new Handler(drive, odometry);
	sm = new StateManager(handler);
	im = new InputManager(server);
}

// singleton implementation
Robot* Robot::getInstance()
{
	if (instance == NULL) {
		instance = new Robot();
		return instance;
	}
}

Server* Robot::getServer()
{
	return Robot::server;
}

DifferentialDrive* Robot::getDrive()
{
	return Robot::drive;
}

Odometry* Robot::getOdometry()
{
	return Robot::odometry;
}

State* Robot::getCurrentState()
{
	return currentState;
}

void Robot::setCurrentState(State* state)
{
	currentState = state;
}

StateManager* Robot::getStateManager()
{
	return sm;
}

InputManager* Robot::getInputManager()
{
	return im;
}






