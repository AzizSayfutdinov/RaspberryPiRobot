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

		atomic<double> increaseTickBy = (((this->motor->getPower() / 100) * resolution) * ((double)simEncoderCycleTime / 1000));
		ticks = ticks + increaseTickBy;
	}
}

long SimEncoder::getTicks() {
	return (long)ticks;
}
