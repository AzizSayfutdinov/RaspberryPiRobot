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
#include "InputManager.h"
#include "State.h"

#define LED 17

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75 
#define KEY_RIGHT 77
#define KEY_EXIT 78

#define COMPASS_ID 0x60

using namespace std;
using namespace std::chrono;

// ==== Test Functions ====
int testTCP();
void setup();
void testTicks(RPiMotor* motor, RPiEncoder* encoder);
void testDriveForwardBackwards(DifferentialDrive* drive, Odometry* odometry);
void testTurningLeftRight(DifferentialDrive* drive, Odometry* odometry);
void testCompass();
void testEncoderFunc();



// ==== MAIN =====
int main(void)
{
	setup();
	
	// TODO: exit with exit code from GUI: while robot->getServer()->reveiveData() != "Exit" in MAIN LOOP	

	Robot* robot = new Robot();
	State* currentState;

	ServerObserver* so = new ServerObserver();
	robot->getServer()->attach(so);
	InputManager* im = new InputManager(robot->getServer());

	while (true) {

		char c = im->getInput();

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

	return 0;
}


// TEST FUNCTION IMPLEMENTATIONS

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

void testCompass() {
	RPiCompassI2C* compass = new RPiCompassI2C(COMPASS_ID);

	while (true) {

		cout << "Value 8 bit: " << compass->getDirection8bit() << "\t Value 16 bit: " << compass->getDirection() << endl;
		this_thread::sleep_for(chrono::milliseconds(250));
	}
}

void testEncoderFunc() {
	 // Test Encoder functionality
	 while (true) {
 		int x = digitalRead(ENCODER_RIGHT);
 		int y = digitalRead(ENCODER_LEFT);
 		cout << "Value right: " << x << "\tValue left: " << y << endl;
 		this_thread::sleep_for(chrono::milliseconds(100));
	 }
}