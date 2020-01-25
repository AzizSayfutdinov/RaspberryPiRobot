#include "IdleState.h"

IdleState::IdleState(Handler* handler) {
	this->handler = handler;
}

void IdleState::execute() {
	// robot->getDrive()->stop();
	handler->drive->stop();
}