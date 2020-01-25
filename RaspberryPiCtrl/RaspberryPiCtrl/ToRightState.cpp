#include "ToRightState.h"

ToRightState::ToRightState(Handler* handler) {
	this->handler = handler;
}

void ToRightState::execute()
{
	// robot->getDrive()->turnRight(0);
	handler->drive->turnRight(0);
}
