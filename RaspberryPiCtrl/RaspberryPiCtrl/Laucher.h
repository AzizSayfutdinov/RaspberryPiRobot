#pragma once
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <softPwm.h>
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h> // for linux
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <chrono>
#include "RPiEncoder.h"
#include "RPiMotor.h"
#include "DifferentialDrive.h"
#include "Odometry.h"
#include "Server.h"
#include "Robot.h"
#include "RPiCompassI2C.h"
#include "InputManager.h"
#include "StateManager.h"
#include "State.h"
#include "MyFunctions.h"

using namespace std;
using namespace std::chrono;

class Laucher
{
private: 
	Robot* robot;
public: 
	void start();
};

