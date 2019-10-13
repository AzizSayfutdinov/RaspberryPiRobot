// CRO.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <thread>
#include <chrono>

#include "SimMotor.h"
#include "SimEncoder.h"

#include "DifferentialDrive.h"
#include "Odometry.h"

using namespace std;

// Test functions
void test_drive(DifferentialDrive* drive, Odometry* odometry);


int main()
{
	std::cout << "------ Testing SimEncoder -----\n";

	SimMotor* motorLeft = new SimMotor();
	SimMotor* motorRight = new SimMotor();
	SimEncoder* simEncoderLeft = new SimEncoder(motorLeft);
	SimEncoder* simEncoderRight = new SimEncoder(motorRight);

	// Test Encoder & Moter simulation
	simEncoderLeft->testSimEncoder();

	// Test drive 
	// DifferentialDrive* diffDrive = new DifferentialDrive(motorLeft, motorRight);
	// Odometry* odometry = new Odometry(simEncoderLeft, simEncoderRight);
	// test_drive(diffDrive, odometry);

	return 0;
}


// Test functions
void test_drive(DifferentialDrive* drive, Odometry* odometry) {
	double distance = 0;
	int timeSteps = 100;
	odometry->reset();
	drive->moveForward();

	while (distance < 100) {

		this_thread::sleep_for(chrono::milliseconds(timeSteps));
		distance = odometry->getDistance();
		cout << distance << " mm" << endl;


	}
}


