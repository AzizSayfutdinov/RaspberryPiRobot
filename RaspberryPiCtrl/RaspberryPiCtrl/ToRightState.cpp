#include "ToRightState.h"

ToRightState::ToRightState(Robot* robot) {
	this->robot = robot;
}

void ToRightState::execute()
{
	robot->getDrive()->turnRight(0);
}
