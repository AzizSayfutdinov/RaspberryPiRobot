#include "ToRightState.h"

ToRightState::ToRightState(Robot* robot) {
	this->robot = robot;
}

int ToRightState::execute()
{
	robot->getDrive()->turnRight(0);
	return 0;
}
