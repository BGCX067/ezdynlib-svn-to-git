// Windows version
//#include <windows.h>
#include <math.h>
#include <limits>
#include <stdio.h>
#include <iostream>
#include "../dynamixel.h"
#include "servo.h"

/*
 * servo.cpp
 *
 *  Created on: 5. okt. 2011
 *      Author: Lars
 */

//#pragma comment(lib, "dynamixel.lib");

//int id;
//Communication *comm;
//bool port;

// Initializes the servos.
Servo::Servo(int id, Communication *comm) : id(id), comm(comm) {
	//this->id = id;
	//this->comm = comm;
	//this->port = true;

	dxl_ping(this->id);
	if(dxl_get_result()==COMM_RXSUCCESS)
	{
		std::cout << "Ping " << BROADCAST_ID << std::endl;
	}
}

Servo::Servo() {

}

//TODO set servo illegal positions to avoid conflicts with robot hardware.

int Servo::getType() {
	int type = comm->getInfo(id, 0);
	if (type == -1) {
		std::cout << "Error getting type" << std::endl;
		return -1;
	}
	return type;
}

int Servo::getCWAngleLimit() {
	int cwAngleLimit = comm->getInfo(id, 6);
	if (cwAngleLimit == -1) {
		std::cout << "Error getting cwAngleLimit" << std::endl;
		return -1;
	}
	return cwAngleLimit;
}
int Servo::getCCWAngleLimit() {
	int ccwAngleLimit = comm->getInfo(id, 8);
	if (ccwAngleLimit == -1) {
		std::cout << "Error getting ccwAngleLimit" << std::endl;
		return -1;
	}
	return ccwAngleLimit;
}

int Servo::getAngle() {
	int angle = comm->getInfo(id, 36);
	if (angle == -1) {
		std::cout << "Error getting servo angle" << std::endl;
		return -1;
	}
	return angle;
}

int Servo::getTemp(){
    int temp = comm->getInfo(id, 43);
    if(temp == -1){
        std::cout << "Error getting temperature" << std::endl;
        return -1;
    }
    return temp;
}

int Servo::getLoad(){
    int load = comm->getInfo(id, 40);
    if(load == -1){
        std::cout << "Error getting load" << std::endl;
        return -1;
    }
    return load;
}

int Servo::getVolt(){
    int volt = comm->getInfo(id, 42);
    if(volt == -1){
        std::cout << "Error getting volt" << std::endl;
        return -1;
    }
    return volt;
}

int Servo::getId(){
    return this->id;
}

int Servo::isMoving() {
    return comm->getInfo(id, 46);
}

int Servo::getSpeed() {
    return comm->getInfo(id, 32);
}

