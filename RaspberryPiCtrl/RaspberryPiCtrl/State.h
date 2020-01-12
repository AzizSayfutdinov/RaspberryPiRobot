#pragma once

// Interface defining the transition functions
class State
{

public: 
	// Transitions with timeout Timer
	virtual int execute() = 0;
};

