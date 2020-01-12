#include "ToLeftState.h"

ToLeftState::ToLeftState(Robot* robot) {
	this->robot = robot;
}

int ToLeftState::execute()
{
	robot->getDrive()->turnLeft();
	return 0;
}
