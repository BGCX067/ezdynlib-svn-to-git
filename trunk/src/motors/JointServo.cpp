/*
 * JointServo.cpp
 *
 *  Created on: 27. okt. 2011
 *      Author: Lars
 */
#include <stdio.h>
#include <iostream>

#include "servo.h"
#include "../dynamixel.h"
#include "../Communication.h"
#include "JointServo.h"

// Initializes the servos.
JointServo::JointServo(int id, Communication *comm) : Servo(id, comm) {
	setJointMode(true);
}

JointServo::JointServo() : Servo() {
}


int JointServo::setJointMode(bool jointMode) {
	if (comm->sendCommand(id, 6, 0) != COMM_RXSUCCESS) {
			std::cout << "Error setting joint mode" << std::endl;
			return -1;
		}
	if (comm->sendCommand(id, 8, MAX_ANGL) != COMM_RXSUCCESS) {
				std::cout << "Error setting joint mode" << std::endl;
				return -1;
			}
	return 0;
}

//Sets a new angle to the servo. It takes in an angle
//increment and adds it to the excisting angle.
int JointServo::setStep(int step, int speed) {
	//TODO set to joint mode if in wheel mode?

	if (step < 0 || step > 1023) {
		std::cout << "Error, wrong step size input" << step << ", needs to be between 0 and 1023" << std::endl;
	}
	if (comm->sendCommand(id, 30, step) != COMM_RXSUCCESS) {
		std::cout << "Error setting step" << std::endl;
		return -1;
	}
	if (comm->sendCommand(id, 32, speed) != COMM_RXSUCCESS) {
		std::cout << "Error setting speed" << std::endl;
		return -1;
	}
	return 0;
}

int JointServo::setSpeed(int speed){
    if (comm->sendCommand(id, 32, speed) != COMM_RXSUCCESS) {
            std::cout << "Error setting speed" << std::endl;
            return -1;
    }
    return 0;
}
