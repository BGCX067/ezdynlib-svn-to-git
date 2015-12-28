/*
 * servo.h
 *
 *  Created on: 5. okt. 2011
 *      Author: Lars
 */

#ifndef SERVO_H_
#define SERVO_H_

#include "../Communication.h"

const int MAX_ANGL = 1023;

class Servo {
public:
	Servo(int id, Communication *comm);
	Servo(int id, Communication *comm, bool rightWheel);
	Servo();


	int setAngleMode();
	int setCWAngleLimit();
	int setCCWAngleLimit();

	int changeId();//?

	int getAngle();
	int getSpeed();

	int getCWAngleLimit();
	int getCCWAngleLimit();
	int getType();
	int getTemp();
	int getVolt();
	int getLoad();
	int getId();

	int isMoving();

	int id;
	Communication *comm;

private:
	//bool port;

};

#endif /* SERVO_H_ */
