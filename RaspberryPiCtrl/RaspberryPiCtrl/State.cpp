#include "State.h"

bool State::isActive() {
	return active;
}

void State::setActive(bool active) {
	this->active = active;
}