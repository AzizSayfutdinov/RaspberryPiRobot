#include "State.h"

bool State::isPeriodic() {
	return periodic;
}

void State::setPeriodic(bool periodic) {
	this->periodic = periodic;
}