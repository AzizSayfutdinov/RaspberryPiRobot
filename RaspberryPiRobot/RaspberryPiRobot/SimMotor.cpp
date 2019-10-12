#include "SimMotor.h"
#include <exception>
#include <iostream>

using namespace std;

SimMotor::SimMotor() {
	this->power = 0;
}

double SimMotor::getPower() {
	return power;
}

void SimMotor::setPower(double power) {
	try {
		if (power >= 0 && power <= 100) {
			this->power = power;
		}
		else {
			cout << "Power has to be between 0 .. 100. " << endl;
		}
	}
	catch (_exception& e) {
		// TODO: implement proper exception
	}

}