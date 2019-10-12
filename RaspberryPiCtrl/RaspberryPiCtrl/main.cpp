#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <softPwm.h>
#include <thread>
#include <iostream>

#include "RPiEncoder.h"
#include "RPiMotor.h"

using namespace std;

// ==== Functions ====
void setup() {
	wiringPiSetupGpio();

	pinMode(ENCODER_LEFT, INPUT);
	pinMode(ENCODER_RIGHT, INPUT);
	
	pinMode(MOTOR_RIGHT_POS, OUTPUT);
	pinMode(MOTOR_RIGHT_NEG, OUTPUT);
	pinMode(MOTOR_LEFT_POS, OUTPUT);
	pinMode(MOTOR_LEFT_NEG, OUTPUT);

	int PwmSuccessful_M1pos = softPwmCreate(MOTOR_RIGHT_POS, 0, 100);
	int PwmSuccessful_M1neg = softPwmCreate(MOTOR_RIGHT_NEG, 0, 100);
	int PwmSuccessful_M2pos = softPwmCreate(MOTOR_LEFT_POS, 0, 100);
	int PwmSuccessful_M2neg = softPwmCreate(MOTOR_LEFT_NEG, 0, 100);

}

void test_ticks(RPiMotor* motor, RPiEncoder* encoder) {

	int currentTickCount = 0;
	
	for (int i = 0; i < 30; i++) {
		if (i == 10) {
			motor->setPower(50);
		}
		if (i == 20) {
			motor->setPower(100);
		}

		currentTickCount = encoder->getTicks();
		cout << "Ticks: " << currentTickCount << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	motor->setPower(0);
}


// ==== MAIN =====
int main(void)
{
	setup();

	RPiMotor* motorRight = new RPiMotor(MOTOR_RIGHT_POS, MOTOR_RIGHT_NEG);
	RPiEncoder* encoderRight = new RPiEncoder(ENCODER_RIGHT);

	test_ticks(motorRight, encoderRight);


	// TEIL 1
	// motorRight->setPower(50);
	// 
	// int encoderRightValue = 99;
	// int encoderLeftValue = 99;
	// 
	// for (int i = 0; i < 30; i++) {
	// 	encoderLeftValue = digitalRead(ENCODER_LEFT);
	// 	encoderRightValue = digitalRead(ENCODER_RIGHT);
	// 
	// 	cout << "EN_left: " << encoderLeftValue << "\tEN_right: " << encoderRightValue << endl;
	// 	
	// 	this_thread::sleep_for(chrono::milliseconds(10));
	// 
	// }
	// 
	// cout << " TEIL 2" << endl << endl;
	// 
	// // TEIL 2
	// motorRight->setPower(10);
	// 
	// encoderRightValue = 99;
	// encoderLeftValue = 99;
	// 
	// for (int i = 0; i < 30; i++) {
	// 	encoderLeftValue = digitalRead(ENCODER_LEFT);
	// 	encoderRightValue = digitalRead(ENCODER_RIGHT);
	// 
	// 	cout << "EN_left: " << encoderLeftValue << "\tEN_right: " << encoderRightValue << endl;
	// 
	// 	this_thread::sleep_for(chrono::milliseconds(10));
	// 
	// }

	return 0;
}