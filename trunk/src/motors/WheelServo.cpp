/*
 * WheelServo.cpp
 *
 *  Created on: 27. okt. 2011
 *      Author: Lars
 */
#include <stdio.h>
#include <iostream>

#include "servo.h"
#include "../dynamixel.h"
#include "../Communication.h"
#include "WheelServo.h"

// Initializes the servos.
WheelServo::WheelServo(int id, Communication *comm, bool port) : Servo(id, comm), port(port) {
	setWheelMode(true);
}

WheelServo::WheelServo() : Servo() {

}


int WheelServo::setWheelMode(bool wheelMode) {
	if (comm->sendCommand(id, 6, 0) != COMM_RXSUCCESS) {
			std::cout << "Error setting wheel mode" << std::endl;
			return -1;
		}
	if (comm->sendCommand(id, 8, 0) != COMM_RXSUCCESS) {
				std::cout << "Error setting wheel mode" << std::endl;
				return -1;
			}
	return 0;
}

//Sets the speed of a wheel servo.
int WheelServo::setWheelSpeed(int speed) {
	//TODO set to wheelmode if in joint mode.

	//The wheels on the right side needs a negative value to go forward.
	//TODO
	/*if (rightWheel)
		speed = -speed;

	//Negative values needs to be sent as 1023+the absolute value of the negative value.
	if(speed < 0)
		speed = abs(speed)+MAX_ANGL;
*/
	//A less pedagogical way to do this would be:
	if (!this->port) {
		std::cout << !this->port << " " << speed <<std::endl;
		speed = speed + MAX_ANGL;
	}

	if (comm->sendCommand(id, 32, speed) != COMM_RXSUCCESS) {
		std::cout << "Error setting wheel speed" << std::endl;
		return -1;
	}
	return 0;
}
