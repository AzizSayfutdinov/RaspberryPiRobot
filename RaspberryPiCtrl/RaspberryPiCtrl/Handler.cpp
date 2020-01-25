#include "Handler.h"

Handler::Handler(DifferentialDrive* drive, Odometry* odometry)
{
	this->drive = drive;
	this->odometry = odometry;
}
