#include "ToRightState.h"

ToRightState::ToRightState(Robot* robot) {
	this->robot = robot;
}

void* ToRightState::execute(void*)
{
	robot->getDrive()->turnRight(0);
	return 0;
}
