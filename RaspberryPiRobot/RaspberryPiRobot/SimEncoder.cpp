#include "SimEncoder.h"
#include <iostream>

using namespace std;

SimEncoder::SimEncoder(SimMotor* motor) {
	stopThread = false;
	this->motor = motor;
	ticks = 0;
	workerThread = thread(&SimEncoder::run, this);
}
SimEncoder::~SimEncoder() {
	stopThread = true;
	workerThread.join();
}

void SimEncoder::run() {
	while (!stopThread) {
		this_thread::sleep_for(chrono::milliseconds(simEncoderCycleTime));

		// cout << "calculation ticks\n";
		ticks = ticks + (((this->motor->getPower() / 100) * resolution) * ((double)simEncoderCycleTime / 1000));
	}
}

long SimEncoder::getTicks() {
	return (long)ticks;
}

void SimEncoder::testSimEncoder() {

	int timeSteps = 100;
	int timePassed = 0;


	for (int i = 0; i <= 30; i++) {

		cout << timePassed << "ms: " << this->getTicks() << " Ticks" << endl;
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