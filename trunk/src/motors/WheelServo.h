/*
 * WheelServo.h
 *
 *  Created on: 27. okt. 2011
 *      Author: Lars
 */

#ifndef WHEELSERVO_H_
#define WHEELSERVO_H_

class WheelServo : public Servo {
	public:
		WheelServo(int id, Communication *comm, bool port = true);
		WheelServo();

		int setWheelMode(bool wheelMode);
		int setWheelSpeed(int speed);

	private:
		bool port;

};


#endif /* WHEELSERVO_H_ */
