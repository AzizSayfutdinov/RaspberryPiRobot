#pragma once
#include <exception>

using namespace std;

struct OutOfBoundariesException : public exception {
	const char* what() const throw() {
		return "Set values are out of acceptable boundaries. ";
	}
};