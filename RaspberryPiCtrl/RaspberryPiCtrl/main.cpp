#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <softPwm.h>
#include <thread>
#include <iostream>
#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h> // for linux
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

#include <chrono>

#include "RPiEncoder.h"
#include "RPiMotor.h"
#include "DifferentialDrive.h"
#include "Odometry.h"
#include "Server.h"
#include "Robot.h"
#include "RPiCompassI2C.h"

#define LED 17

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75 
#define KEY_RIGHT 77
#define KEY_EXIT 78

#define COMPASS_ID 0x60

using namespace std;
using namespace std::chrono;

// ==== Functions ====
void setup() {
	wiringPiSetupGpio();

	pinMode(ENCODER_LEFT, INPUT);
	pinMode(ENCODER_RIGHT, INPUT);

	pinMode(MOTOR_RIGHT_POS, OUTPUT);
	pinMode(MOTOR_RIGHT_NEG, OUTPUT);
	pinMode(MOTOR_LEFT_POS, OUTPUT);
	pinMode(MOTOR_LEFT_NEG, OUTPUT);

	// TODO: add exceptions if softPWM creation fails
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

void testTurningLeftRight(DifferentialDrive* drive, Odometry* odometry) {
	odometry->reset();
	drive->turnLeft();
	delay(400);
	drive->stop();

	delay(500);

	drive->turnRight();
	delay(400);
	drive->stop();

	// RPiMotor::resetAll();

}

int testTCP() {

	// == Setup TCP Server == 
	// create a socket
	int listening = socket(AF_INET, SOCK_STREAM, 0);		// INET = IPv4; listening is a socket descriptor
	if (listening == -1) {
		cerr << "Can't create a socket!";
		return -1;
	}

	// Bind the socket to a IP address and port
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_addr.s_addr = INADDR_ANY;		// automatically be filled with current host's IP address
	hint.sin_port = htons(54000);
	inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);		// defining the struture of the socket; "0.0.0.0" means eny address, dara conversion

	if (bind(listening, (sockaddr*)&hint, sizeof(hint)) == -1) {
		cerr << "Can't bind to IP/port";
		return -2;
	}


	// Mark the socket for listening
	if (listen(listening, SOMAXCONN) == -1) {
		cerr << "Can't listen!";
		return -3;
	}


	// Accept a call
	sockaddr_in client;
	socklen_t clientSize = sizeof(client);
	char host[NI_MAXHOST];		// buffers
	char svc[NI_MAXSERV];

	int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	if (clientSocket == -1) {
		cerr << "Problem with client connetion!";
		return -4;
	}

	// Close socket
	close(listening);


	// Greet Client!
	cout << "Initiate Greeting of client! Code Red!";
	char greeting[] = "Hi Client! What's up!";
	send(clientSocket, greeting, sizeof(greeting) + 1, 0);

	// cleaning up garbage
	memset(host, 0, NI_MAXHOST);
	memset(svc, 0, NI_MAXSERV);

	int result = getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV, 0);

	if (result) {
		cout << host << " connected on " << svc << endl;
	}
	else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);				// opposite of inet_pton, numeric array to string conversion
		cout << host << " connected on " << ntohs(client.sin_port) << endl;
	}


	char buffer[4096];
	while (true) {
		// clear buffer
		memset(buffer, 0, 4096);

		// wait for a massage
		int bytesRevc = recv(clientSocket, buffer, 4096, 0);
		if (bytesRevc == -1) {
			cerr << "There was a connection issue" << endl;
			break;
		}

		if (bytesRevc == 0) {
			cout << "The client disconnected" << endl;
			break;
		}

		// Display message
		cout << "Received: " << string(buffer, 0, bytesRevc) << endl;

		// echo back out: Resend message
		send(clientSocket, buffer, bytesRevc + 1, 0);

		if (buffer[0] == 'a') {
			digitalWrite(LED, HIGH);
		}
		if (buffer[0] == 'b') {
			digitalWrite(LED, LOW);
		}

	}

	// Close the socket
	close(clientSocket);
	return 1;
}


// ==== MAIN =====
int main(void)
{
	setup();

	// RPiMotor* motorRight = new RPiMotor(MOTOR_RIGHT_POS, MOTOR_RIGHT_NEG);
	// RPiMotor* motorLeft = new RPiMotor(MOTOR_LEFT_POS, MOTOR_LEFT_NEG);
	// RPiEncoder* encoderLeft = new RPiEncoder(ENCODER_LEFT);
	// RPiEncoder* encoderRight = new RPiEncoder(ENCODER_RIGHT);
	// 
	// DifferentialDrive* drive = new DifferentialDrive(motorLeft, motorRight);
	// Odometry* odometry = new Odometry(encoderLeft, encoderRight);

	// while (true) {
	// 	this_thread::sleep_for(chrono::milliseconds(250));
	// 	digitalWrite(LED, HIGH);
	// 	this_thread::sleep_for(chrono::milliseconds(250));
	// 	digitalWrite(LED, LOW);
	// }

	// testTCP();

	// Server* server = new Server();
	
	// exit with exit code from GUI: while robot->getServer()->reveiveData() != "Exit"

	RPiCompassI2C* compass = new RPiCompassI2C(COMPASS_ID);

	while (true) {
	
		cout << "Value 8 bit: " << compass->getDirection8bit() << "\t Value 16 bit: " << compass->getDirection() << endl;
		this_thread::sleep_for(chrono::milliseconds(250));
	}


	// MAIN LOOP
	Robot* robot = new Robot();
	while (true) {
		robot->getServer()->receiveData();
		char* buffer = robot->getServer()->getBuffer();
		char c = buffer[0];
	
		long timeout = 200;		// in ms
	
		int lastTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
	
		int diff = 0;

		if (c == 'a') {
			robot->getOdometry()->alignNorth(robot->getDrive());
		}
	
		while (diff < timeout) {
	
			switch (c)
			{
			case 'f': 
				robot->getDrive()->moveForward();
				break;
			case 'b':
				robot->getDrive()->moveBackward();
				break;
			case 's':
				robot->getDrive()->stop();
				break;
			case 'r':
				robot->getDrive()->turnRight();
				break;
			case 'l':
				robot->getDrive()->turnLeft();
				break;
			default:
				break;
			}
	
	
			int currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
			diff = currentTime - lastTime;
		}
		robot->getDrive()->stop();
	
	}










	// testTurningLeftRight(drive, odometry);
	// this_thread::sleep_for(chrono::milliseconds(100));
	// testDriveForwardBackwards(drive, odometry);

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