#include "IdleState.h"

IdleState::IdleState(Robot* robot) {
	this->robot = robot;
}

void IdleState::execute() {
	robot->getDrive()->stop();
}