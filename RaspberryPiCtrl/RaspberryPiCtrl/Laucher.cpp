#include "Laucher.h"

Robot* Robot::instance = NULL;
DifferentialDrive* DifferentialDrive::instance = NULL;

void Laucher::start()
{
	setup();

	Robot* robot = Robot::getInstance();
	int timeout = 75;			// in ms

	while (true) {

		int diff = 0;
		bool once = true;
		char c = robot->getInputManager()->getInput();

		int lastTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

		robot->setCurrentState(robot->getStateManager()->updateCurrentState(c));

		while (diff < timeout) {
			if (robot->getCurrentState()->isPeriodic()) {		// LED state should execute only once within timeout
				if (once) {
					robot->getCurrentState()->execute();
					once = false;
				}
			}
			else
			{
				robot->getCurrentState()->execute();
			}
			int currentTime = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
			diff = currentTime - lastTime;
		}
		robot->getDrive()->stop();
	}

	delete robot;
}
