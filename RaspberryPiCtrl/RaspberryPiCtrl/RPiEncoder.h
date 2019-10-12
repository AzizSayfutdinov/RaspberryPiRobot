#pragma once
#include "Encoder.h"
#include <atomic>
#include <thread>
#include <pthread.h>

#define ENCODER_RIGHT 22
#define ENCODER_LEFT 23

using namespace std;

class RPiEncoder
{
private: 
	int EncoderPin;
	atomic<bool> stopThread;
	atomic<long> ticks;
	thread workerThread;

public: 
	RPiEncoder(int EncoderPin);
	~RPiEncoder();
	void run();
	long getTicks();
	
};

