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




