#pragma once
#include <vector>

// Problem: Das Observer Pattern ist so ausgelegt, dass das Subject all seine Observer kennt
// Wenn sich der Zustand ändert, dann ruft das Subject die update()-Methode der Observer auf. 

// Ich brauche den umgekehrten Fall, dass ich nur einen Observer habe und dafür mehrere Subjects. 
// Lösung: mehrere Observer verwenden. L
// Alternative: Producer/Consumer Pattern

class Observer
{
public: 
	virtual void update() = 0;
};

