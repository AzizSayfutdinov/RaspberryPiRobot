#include "ToLeftState.h"

ToLeftState::ToLeftState(Handler* handler) {
	this->handler = handler;
}

void ToLeftState::execute()
{
	// robot->getDrive()->turnLeft(0);
	handler->drive->turnLeft(0);
}
