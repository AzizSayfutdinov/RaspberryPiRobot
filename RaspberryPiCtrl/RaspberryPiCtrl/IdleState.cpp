#include "IdleState.h"

int IdleState::execute() {
	robot->getDrive()->stop();
	return 0;
}