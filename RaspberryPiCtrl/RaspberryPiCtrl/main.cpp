#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <softPwm.h>
#include <thread>
#include <iostream>
#include <stdio.h>

#include "RPiEncoder.h"
#include "RPiMotor.h"
#include "DifferentialDrive.h"
#include "Odometry.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75 
#define KEY_RIGHT 77
#define KEY_EXIT 78

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

	// TODO: add expections if softPWM creation fails
	int PwmSuccessful_M1pos = softPwmCreate(MOTOR_RIGHT_POS, 0, 100);
	int PwmSuccessful_M1neg = softPwmCreate(MOTOR_RIGHT_NEG, 0, 100);
	int PwmSuccessful_M2pos = softPwmCreate(MOTOR_LEFT_POS, 0, 100);
	int PwmSuccessful_M2neg = softPwmCreate(MOTOR_LEFT_NEG, 0, 100);

}


void testTicks(RPiMotor* motor, RPiEncoder* encoder) {

	int currentTickCount = 0;
	
	for (int i = 0; i < 100; i++) {

		motor->setPower(100);

		// if (i == 0) {
		// 	motor->setPower(100);
		// }
		// if (i == 20) {
		// 	motor->setPower(100);
		// }

		currentTickCount = encoder->getTicks();
		cout << "Ticks: " << currentTickCount << endl;
		this_thread::sleep_for(chrono::milliseconds(10));
	}
	motor->setPower(0);
}

void testKeyboardInput() {		// does not work like this: cross compilation needed
	bool running = true;
	int c = 0;
	while (running)
	{
		c = 0;
		this_thread::sleep_for(chrono::milliseconds(50));
		cout << endl << "Output:  " << c << endl; // exit key - ESC
		c = getchar();
		switch (c) {
		case KEY_UP:
			cout << endl << "Up: " << c << endl;//key up
			break;
		case KEY_DOWN:
			cout << endl << "Down: " << c << endl;   // key down
			break;
		case KEY_LEFT:
			cout << endl << "Left: " << c << endl;  // key left
			break;
		case KEY_RIGHT:
			cout << endl << "Right: " << c << endl;  // key right
			break;
		case KEY_EXIT: 
			running = false;
			cout << endl << "Ending program:  " << c << endl; // exit key - ESC
		default:
			cout << endl << "null" << endl;  // not arrow
			break;
		}


	}
}

void testDriveForwardBackwards(DifferentialDrive* drive, Odometry* odometry) {
	
	int dist = 0;
	odometry->reset();
	drive->moveForward();
	this_thread::sleep_for(chrono::milliseconds(1000));
	drive->stop();
	dist = odometry->getDistance();
	cout << "Distance traveled: " << dist << "mm " << endl;	

	delay(1000);

	odometry->reset();
	drive->moveBackward();
	this_thread::sleep_for(chrono::milliseconds(1000));
	drive->stop();
	dist = odometry->getDistance();
	cout << "Distance traveled: " << dist << "mm " << endl;
	// RPiMotor::turnOffAll();
}


// ==== MAIN =====
int main(void)
{
	setup();

	RPiMotor* motorRight = new RPiMotor(MOTOR_RIGHT_POS, MOTOR_RIGHT_NEG);
	RPiMotor* motorLeft = new RPiMotor(MOTOR_LEFT_POS, MOTOR_LEFT_NEG);
	RPiEncoder* encoderLeft = new RPiEncoder(ENCODER_LEFT);
	RPiEncoder* encoderRight = new RPiEncoder(ENCODER_RIGHT);

	DifferentialDrive* drive = new DifferentialDrive(motorLeft, motorRight);
	Odometry* odometry = new Odometry(encoderLeft, encoderRight);

	testDriveForwardBackwards(drive, odometry);




	// testTicks(motorRight, encoderRight);

	// testKeyboardInput();		// cross compilation needed

	// Test Encoder functionality
	// while (true) {
	// 	int x = digitalRead(ENCODER_RIGHT);
	// 	int y = digitalRead(ENCODER_LEFT);
	// 	cout << "Value right: " << x << "\tValue left: " << y << endl;
	// 	this_thread::sleep_for(chrono::milliseconds(100));
	// }


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