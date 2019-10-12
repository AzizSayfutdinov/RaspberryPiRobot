// SimEncoder
#pragma once
#include <thread>
#include <atomic>
#include <chrono>

#include "SimMotor.h"
#include "Encoder.h"

using namespace std;

class SimEncoder:public Encoder
{
private:
	const double maxRps = 1;		// maximal rotations per second
	SimMotor* motor;
	const long resolution = 20;		// encoder resolution
	const long simEncoderCycleTime = 100; // in ms
	atomic<bool> stopThread;
	atomic<double> ticks;
	thread workerThread;		

public:
	SimEncoder(SimMotor* motor);
	~SimEncoder();
	void run();
	long getTicks();
	void testSimEncoder();

};



