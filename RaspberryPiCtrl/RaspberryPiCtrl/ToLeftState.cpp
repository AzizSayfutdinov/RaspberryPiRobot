#include "ToLeftState.h"

int ToLeftState::execute()
{
	robot->getDrive()->turnLeft();
	return 0;
}
