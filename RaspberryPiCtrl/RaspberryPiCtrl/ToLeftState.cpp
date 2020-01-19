#include "ToLeftState.h"

ToLeftState::ToLeftState(Robot* robot) {
	this->robot = robot;
}

int ToLeftState::execute()
{
	robot->getDrive()->turnLeft(0);
	return 0;
}
