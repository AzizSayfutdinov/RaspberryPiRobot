#include "ToRightState.h"

int ToRightState::execute()
{
	robot->getDrive()->turnRight();
	return 0;
}
