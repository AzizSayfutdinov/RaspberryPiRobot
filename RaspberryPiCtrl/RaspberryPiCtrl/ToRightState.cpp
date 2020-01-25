#include "ToRightState.h"

ToRightState::ToRightState(Handler* handler) {
	this->handler = handler;
}

void ToRightState::execute()
{
	handler->drive->turnRight(0.4);
}
