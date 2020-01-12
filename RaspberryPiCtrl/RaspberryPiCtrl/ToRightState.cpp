#include "ToRightState.h"

ToRightState::ToRightState(Robot* robot) {
	this->robot = robot;
}

int ToRightState::execute()
{
	robot->getDrive()->turnRight();
	return 0;
}
