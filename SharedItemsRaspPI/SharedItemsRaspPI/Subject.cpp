#include "Subject.h"
#include "Observer.h"
#include <iterator>

void Subject::attach(Observer* observer) {
	observers->push_back(observer);
}

void Subject::detach(Observer* observer) {
	observers->remove(observer);
}

void Subject::notify(){

	list<Observer*>::iterator it;

	for (it = observers->begin(); it != observers->end(); ++it) {
		Observer* o = *it;
		o->update(this);
	}


}
