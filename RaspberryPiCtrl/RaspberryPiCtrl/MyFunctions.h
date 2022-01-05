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
#include "Handler.h"
#include "LedOnOffState.h"
#include "IdleState.h"
#include "Button.h"

#pragma region Defines
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75 
#define KEY_RIGHT 77
#define KEY_EXIT 78
#define COMPASS_ID 0x60
#pragma endregion

using namespace std;
using namespace std::chrono;

void setup();
int testTCP();
void testTicks(RPiMotor* motor, RPiEncoder* encoder);
void testDriveForwardBackwards(DifferentialDrive* drive, Odometry* odometry);
void testTurningLeftRight(DifferentialDrive* drive, Odometry* odometry);
void testCompass();
void testEncoderFunc();
void testDrive();
void testButton();