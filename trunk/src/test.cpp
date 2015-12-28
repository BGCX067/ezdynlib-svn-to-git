/*
 * test.cpp
 *
 *  Created on: 13. okt. 2011
 *      Author: Lars
 */
// Windows version
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif
#include <math.h>
#include <limits>
#include <stdio.h>
#include <iostream>
#include "motors//servo.h"
#include "motors//WheelServo.h"
#include "motors//JointServo.h"

#ifdef __linux__
void Sleep(int ms) {
usleep(ms); //convert to microseconds
return;
}
#endif

int main() {
	Communication *comm = new Communication();
	if (comm->connect()) {
		JointServo *servo1 = new JointServo(1, comm);
		WheelServo *servo2 = new WheelServo(2, comm);
		std::cout << "2 Type: " << servo2->getType() << std::endl;
		std::cout << "2 CW limit: " << servo2->getCWAngleLimit() << std::endl;
		std::cout << "2 CCW limit: " << servo2->getCCWAngleLimit() << std::endl;
		std::cout << "1 Type: " << servo1->getType() << std::endl;
		std::cout << "1 CW limit: " << servo2->getCWAngleLimit() << std::endl;
		std::cout << "1 CCW limit: " << servo2->getCCWAngleLimit() << std::endl;
		servo2->setWheelSpeed(100);
		Sleep(3000);
		servo2->setWheelSpeed(0);
/*

		std::cout << "Set 500" << std::endl;
		servo1->setStep(700, 200);
		Sleep(3000);
		std::cout << "Set 1000" << std::endl;
		servo1->setStep(1000, 200);


		JointServo *servo2Joint = new JointServo(2, comm);
		WheelServo *servo1Wheel = new WheelServo(1, comm);
		servo1Wheel->setWheelSpeed(100);
		Sleep(3000);
		servo1Wheel->setWheelSpeed(0);


		std::cout << "Set 500" << std::endl;
		servo2Joint->setStep(700, 200);
		Sleep(3000);
		std::cout << "Set 1000" << std::endl;
		servo2Joint->setStep(1000, 200);
*/

		/*std::cout << "Set 200" << std::endl;
		servo2->setAngle(200, 250);
		Sleep(3000);
		std::cout << "Set 500" << std::endl;
		servo2->setAngle(400, 200);
		std::cout << "1 angl: " << servo1->getAngle() << std::endl;
		std::cout << "2 angl: " << servo2->getAngle() << std::endl;
*/
		//servo2->setWheelMode(true);
		//servo2->setWheelSpeed(50);
		//Sleep(3000);
		//servo2->setWheelSpeed(0);

	} else {
		std::cout << "could not connect" << std::endl;
		return -1;
	}
	return 0;
}
