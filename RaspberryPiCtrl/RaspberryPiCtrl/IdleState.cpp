#include "IdleState.h"

IdleState::IdleState(Robot* robot) {
	this->robot = robot;
}

int IdleState::execute() {
	robot->getDrive()->stop();
	return 0;
}