#include "IdleState.h"

IdleState::IdleState(Robot* robot) {
	this->robot = robot;
}

void* IdleState::execute(void*) {
	robot->getDrive()->stop();
	return 0;
}