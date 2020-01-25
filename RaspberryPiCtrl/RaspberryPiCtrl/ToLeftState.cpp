#include "ToLeftState.h"

ToLeftState::ToLeftState(Robot* robot) {
	this->robot = robot;
}

void ToLeftState::execute()
{
	robot->getDrive()->turnLeft(0);
}
