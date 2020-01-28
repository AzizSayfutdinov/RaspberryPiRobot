#include "MyFunctions.h"

void setup() {
	wiringPiSetupGpio();

	pinMode(ENCODER_LEFT, INPUT);
	pinMode(ENCODER_RIGHT, INPUT);

	pinMode(MOTOR_RIGHT_POS, OUTPUT);
	pinMode(MOTOR_RIGHT_NEG, OUTPUT);
	pinMode(MOTOR_LEFT_POS, OUTPUT);
	pinMode(MOTOR_LEFT_NEG, OUTPUT);

	// TODO: add exceptions if softPWM creation fails
	int PWM_OK = softPwmCreate(MOTOR_RIGHT_POS, 0, 100);
	if (!PWM_OK) {
		cout << "PWM for MOTOR_RIGHT_POS created successfully." << endl;;
	}

	PWM_OK = softPwmCreate(MOTOR_RIGHT_NEG, 0, 100);
	if (!PWM_OK) {
		cout << "PWM for MOTOR_RIGHT_NEG created successfully. " << endl;;
	}

	PWM_OK = softPwmCreate(MOTOR_LEFT_POS, 0, 100);
	if (!PWM_OK) {
		cout << "PWM for MOTOR_LEFT_POS created successfully. " << endl;;
	}

	PWM_OK = softPwmCreate(MOTOR_LEFT_NEG, 0, 100);
	if (!PWM_OK) {
		cout << "PWM for MOTOR_LEFT_NEG created successfully. " << endl;;
	}
}

// Test Functions
void testButton() {
	Button* b = new Button(23);

	while (true) {
		char a = b->getInput();
		cout << a << endl;
		this_thread::sleep_for(chrono::milliseconds(150));

	}
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
	std::cout << "Initiate Greeting of client! Code Red!";
	char greeting[] = "Hi Client! What's up!";
	send(clientSocket, greeting, sizeof(greeting) + 1, 0);

	// cleaning up garbage
	memset(host, 0, NI_MAXHOST);
	memset(svc, 0, NI_MAXSERV);

	int result = getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, svc, NI_MAXSERV, 0);

	if (result) {
		std::cout << host << " connected on " << svc << endl;
	}
	else {
		inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);				// opposite of inet_pton, numeric array to string conversion
		std::cout << host << " connected on " << ntohs(client.sin_port) << endl;
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
			std::cout << "The client disconnected" << endl;
			break;
		}

		// Display message
		std::cout << "Received: " << string(buffer, 0, bytesRevc) << endl;

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
		std::cout << "Ticks: " << currentTickCount << endl;
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
	std::cout << "Distance traveled: " << dist << "mm " << endl;

	delay(1000);

	odometry->reset();
	drive->moveBackward();
	this_thread::sleep_for(chrono::milliseconds(1000));
	drive->stop();
	dist = odometry->getDistance();
	std::cout << "Distance traveled: " << dist << "mm " << endl;
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

		std::cout << "Value 8 bit: " << compass->getDirection8bit() << "\t Value 16 bit: " << compass->getDirection() << endl;
		this_thread::sleep_for(chrono::milliseconds(250));
	}
}

void testEncoderFunc() {
	// Test Encoder functionality
	while (true) {
		int x = digitalRead(ENCODER_RIGHT);
		int y = digitalRead(ENCODER_LEFT);
		std::cout << "Value right: " << x << "\tValue left: " << y << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	}
}

void testDrive() {

	// drive forward
	int start = 0;
	softPwmWrite(MOTOR_RIGHT_POS, 50);
	softPwmWrite(MOTOR_LEFT_POS, 50);
	this_thread::sleep_for(chrono::milliseconds(2000));		// motors only move, if the system is running (while thread is running)
	// pause
	int a = 0;
	int b = a + 1;
	softPwmWrite(MOTOR_RIGHT_POS, 0);
	softPwmWrite(MOTOR_LEFT_POS, 0);
	this_thread::sleep_for(chrono::milliseconds(2000));

	// turn left
	softPwmWrite(MOTOR_RIGHT_POS, 50);
	softPwmWrite(MOTOR_LEFT_NEG, 50);
	this_thread::sleep_for(chrono::milliseconds(2000));

	//// drive forward: digital
	//digitalWrite(MOTOR_RIGHT_POS, HIGH);
	//digitalWrite(MOTOR_RIGHT_NEG, HIGH);
	//digitalWrite(MOTOR_LEFT_POS, HIGH);
	//digitalWrite(MOTOR_LEFT_NEG, HIGH);
	//this_thread::sleep_for(chrono::milliseconds(2000));

	//// pause
	//digitalWrite(MOTOR_RIGHT_NEG, LOW);
	//digitalWrite(MOTOR_RIGHT_POS, HIGH);
	//digitalWrite(MOTOR_LEFT_NEG, LOW);
	//digitalWrite(MOTOR_LEFT_POS, HIGH);

	this_thread::sleep_for(chrono::milliseconds(2000));
	int stop = 0;



}