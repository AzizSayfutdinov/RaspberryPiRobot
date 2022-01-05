#pragma once
#include "DifferentialDrive.h"
#include "Odometry.h"
#include "Server.h"

// The states need the drive and the odometry to execute their respective state routines. 
// It is not possible to pass the robot as an input parameter because it causes a circular dependency 
// there this helper class is used to solve this issues by passing through the needed parameters

class Handler
{
private: 

public: 
	DifferentialDrive* drive;
	Odometry* odometry;
	Server* server;
	Handler(DifferentialDrive* drive, Odometry* odometry, Server* server);
};

