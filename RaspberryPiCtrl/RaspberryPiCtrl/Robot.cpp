#include "Robot.h"

Robot::Robot()
{
	motorRight = new RPiMotor(MOTOR_RIGHT_POS, MOTOR_RIGHT_NEG);
	motorLeft = new RPiMotor(MOTOR_LEFT_POS, MOTOR_LEFT_NEG);
	drive = DifferentialDrive::getInstance(motorLeft, motorRight);	// singleton implementation

	encoderRight = new RPiEncoder(ENCODER_RIGHT);
	encoderLeft = new RPiEncoder(ENCODER_LEFT);
	compass = new RPiCompassI2C(I2C_ADDRESS);
	odometry = new Odometry(encoderLeft, encoderRight, compass);		
	
	server = new Server();
	im = new InputManager(server);
	server->attach(im);		// attaching inputManager as observer

	button_nr1 = new Button(BUTTON_PIN);
	im->addInputObject(button_nr1);

	handler = new Handler(drive, odometry, server);
	sm = new StateManager(handler);

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






