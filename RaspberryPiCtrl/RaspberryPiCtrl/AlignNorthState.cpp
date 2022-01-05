#include "AlignNorthState.h"

AlignNorthState::AlignNorthState(Handler* handler)
{
	this->handler = handler;
}

void AlignNorthState::execute()
{
	handler->odometry->alignNorth(handler->drive);
}
