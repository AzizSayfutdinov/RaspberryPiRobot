#include "BackwardState.h"

BackwardState::BackwardState(Robot* robot) {
	this->robot = robot;
}

void BackwardState::execute()
{
	if (active) {
		robot->getDrive()->moveBackward();
	}
	
}
