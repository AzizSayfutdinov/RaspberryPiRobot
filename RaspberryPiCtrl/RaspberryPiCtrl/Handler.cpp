#include "Handler.h"

Handler::Handler(DifferentialDrive* drive, Odometry* odometry, Server* server)
{
	this->drive = drive;
	this->odometry = odometry;
	this->server = server;
}
