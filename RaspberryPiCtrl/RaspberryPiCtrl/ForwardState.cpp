#include "ForwardState.h"

// QUESTION: Wieso muss man für jede Subklasse die Methoden des Interfaces nochmals angeben im h-file? 
// Was ist, wenn man die Methoden des Interfaces gar nicht kennt? 
//int State::execute() {
//	robot->getDrive()->moveForward();
//}

ForwardState::ForwardState(Handler* handler) {
	this->handler = handler;
}

void ForwardState::execute() {

	handler->drive->moveForward();
	string s = "\r\nState: Mocing Forward \r\n";
	char cstr[s.size() + 1];
	strcpy(cstr, s.c_str());
	handler->server->sendData(cstr);
}
