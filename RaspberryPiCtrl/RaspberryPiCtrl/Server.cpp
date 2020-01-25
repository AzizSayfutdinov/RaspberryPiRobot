#include "Server.h"
#include <iostream>

Server::Server() {

	Server::setup();

	// // Close socket
	// close(listening);
	// // cleaning up garbage
	// memset(host, 0, NI_MAXHOST);
	// memset(svc, 0, NI_MAXSERV);

}

void Server::clearBuffer()
{
	memset(buffer, 0, 128);
}

void Server::receiveData() {

	memset(buffer, 0, 128);
	int bytesRevc = recv(clientSocket, buffer, 128, 0);
	notify();	// notify observer

}

int Server::setup()
{

	// original implementation
	// if (Server::createSocket() < 0) {
	// 	cerr << "Can't create a socket!";
	// 	return -1;
	// }
	// if (Server::bindSocket() < 0) {
	// 	cerr << "Can't bind to IP/port";
	// 	return -1;
	// }
	// if (Server::acceptCall() < 0) {
	// 	cerr << "Problem with client connetion!";
	// 	return -1;
	// }

	// TODO: clear

	// create a socket
	listening = socket(AF_INET, SOCK_STREAM, 0);		// INET = IPv4; listening is a socket descriptor
	if (listening == -1) {
		cerr << "Can't create a socket!";
		return -1;
	}

	// Bind the socket to a IP address and port
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
		cerr << "Can't listen!" << errno;
		return -3;
	}


	// Accept a call
	clientSize = sizeof(client);

	clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

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

	return 0;

}

int Server::createSocket()
{
	// Create a socket
	listening = socket(AF_INET, SOCK_STREAM, 0);		// INET = IPv4; listening is a socket descriptor
	if (listening == -1) {
		cerr << "Can't create a socket!";
		return -1;
	}

	return 0;
}

int Server::bindSocket()
{
	// Bind the socket to a IP address and port
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

	return 0;

}

int Server::acceptCall()
{
	// Accept a call
	clientSize = sizeof(client);

	clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	if (clientSocket == -1) {
		cerr << "Problem with client connetion!";
		return -4;
	}

	return 0;
}

char* Server::getBuffer()
{
	return buffer;
}





