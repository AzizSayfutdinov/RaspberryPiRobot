#pragma once
#include <vector>
#include "Subject.h"

using namespace std;

class Observer
{
private: 
	vector<Subject*> subjectList;

public: 
	void addSubject(Subject* subject);
	virtual void update() = 0;
	vector<Subject*> getSubjectList();
	
};

