#pragma once
#include "DifferentialDrive.h"
#include "RPiMotor.h"
#include "RPiEncoder.h"
#include "RPiCompassI2C.h"
#include "Odometry.h"
#include "Server.h"

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

public: 
	Robot();
	Server* getServer();
	DifferentialDrive* getDrive();
	Odometry* getOdometry();

};

