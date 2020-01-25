#pragma once
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h> // for linux
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "Subject.h"

using namespace std;

class Server: public Subject
{

private: 
	int listening;
	sockaddr_in hint;
	sockaddr_in client;
	socklen_t clientSize;
	char host[NI_MAXHOST];
	char svc[NI_MAXSERV];
	int clientSocket;
	char buffer[128];

	int setup();
	int createSocket();
	int bindSocket();
	int acceptCall();


public:
	char* getBuffer();
	void receiveData();
	Server();
	void clearBuffer();

};

