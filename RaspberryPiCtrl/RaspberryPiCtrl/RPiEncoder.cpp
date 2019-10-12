#include "RPiEncoder.h"
#include <wiringPi.h>
#include <thread>
#include <pthread.h>
#include <iostream>

using namespace std;

RPiEncoder::RPiEncoder(int EncoderPin) {
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
		cout << "9" << endl;
		this_thread::sleep_for(chrono::milliseconds(1));
		newValue = digitalRead(EncoderPin);

		if (oldValue < newValue) {		// rising edge 
			ticks = ticks + 1;	
		}
		oldValue = newValue;

	}
}

long RPiEncoder::getTicks() {
	return (long)ticks;
}
