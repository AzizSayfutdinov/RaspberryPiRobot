#include "BackwardState.h"

BackwardState::BackwardState(Robot* robot) {
	this->robot = robot;
}

int BackwardState::execute()
{
	robot->getDrive()->moveBackward();
	return 0;
}
