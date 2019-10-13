#include "RPiEncoder.h"
#include <wiringPi.h>
#include <thread>
#include <pthread.h>
#include <iostream>

using namespace std;

RPiEncoder::RPiEncoder(int EncoderPin) {
	stopThread = false;
	this->EncoderPin = EncoderPin;
	ticks = 0;
	workerThread = thread(&RPiEncoder::run, this);	

}

RPiEncoder::~RPiEncoder() {

}

void RPiEncoder::run() {

	ticks = 0;
	int newValue = 0;
	int oldValue = digitalRead(EncoderPin);
	cout << "in the run methode()" << endl;

	while (!stopThread) {
		oldValue = digitalRead(EncoderPin);
		this_thread::sleep_for(chrono::milliseconds(1));
		newValue = digitalRead(EncoderPin);

		if (oldValue == 0 && newValue == 1) {		// rising edge 
			ticks++;	
		}
		oldValue = newValue;

	}
}

long RPiEncoder::getTicks() {
	return (long)ticks;
}
