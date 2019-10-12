// CRO.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <thread>
#include <chrono>

#include "SimMotor.h"
#include "SimEncoder.h"

using namespace std;

void testSimEncoder(SimEncoder* encoder, SimMotor* motor) {

	int timeSteps = 100;
	int timePassed = 0;

	for (int i = 0; i <= 30; i++) {

		cout << timePassed << "ms: " << encoder->getTicks() << " Ticks" << endl;
		if (i == 10) {
			motor->setPower(50);
		}
		if (i == 20) {
			motor->setPower(100);
		}
		this_thread::sleep_for(chrono::milliseconds(timeSteps));
		timePassed += timeSteps;

	}
}

int main()
{
	std::cout << "------ Testing SimEncoder -----\n";

	SimMotor* motorLeft = new SimMotor();
	SimEncoder* simEncoderLeft = new SimEncoder(motorLeft);

	testSimEncoder(simEncoderLeft, motorLeft);


	return 0;
}


