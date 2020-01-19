#include "ToLeftState.h"

ToLeftState::ToLeftState(Robot* robot) {
	this->robot = robot;
}

void* ToLeftState::execute(void*)
{
	robot->getDrive()->turnLeft(0);
	return 0;
}
