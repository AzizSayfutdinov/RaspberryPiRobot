#include "IdleState.h"

IdleState::IdleState(Handler* handler) {
	this->handler = handler;
}

void IdleState::execute() {
	handler->drive->stop();
}