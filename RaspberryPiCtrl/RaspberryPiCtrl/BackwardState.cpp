#include "BackwardState.h"

int BackwardState::execute()
{
	robot->getDrive()->moveBackward();
	return 0;
}
