#include "ForwardState.h"

// QUESTION: Wieso muss man für jede Subklasse die Methoden des Interfaces nochmals angeben im h-file? 
// Was ist, wenn man die Methoden des Interfaces gar nicht kennt? 
//int State::execute() {
//	robot->getDrive()->moveForward();
//}

int ForwardState::execute() {

	robot->getDrive()->moveForward();
	return 0;
}
