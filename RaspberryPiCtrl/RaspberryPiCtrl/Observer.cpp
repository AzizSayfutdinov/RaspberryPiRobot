#include "Observer.h"

void Observer::addSubject(Subject* subject)
{
	subjectList.push_back(subject);
}

vector<Subject*> Observer::getSubjectList()
{
	return subjectList;
}
