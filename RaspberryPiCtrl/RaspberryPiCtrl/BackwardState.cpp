#include "BackwardState.h"

BackwardState::BackwardState(Handler* handler) {
	this->handler = handler;
}

void BackwardState::execute()
{
	if (active) {
		// robot->getDrive()->moveBackward();
		handler->drive->moveBackward();
	}
	
}
