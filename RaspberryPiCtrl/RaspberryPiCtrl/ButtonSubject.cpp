#include "ButtonSubject.h"

void ButtonSubject::notify(int buttonNumber)
{
	for (int i = 0; i < getObserverList()->size(); i++) {
		getObserverList()->at(i)->update(buttonNumber);
	}
}
