#include "BackwardState.h"

BackwardState::BackwardState(Handler* handler) {
	this->handler = handler;
}

void BackwardState::execute()
{
	handler->drive->moveBackward();
}
