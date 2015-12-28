/*
 * JointServo.h
 *
 *  Created on: 27. okt. 2011
 *      Author: Lars
 */

#ifndef JOINTSERVO_H_
#define JOINTSERVO_H_

class JointServo : public Servo {
	public:
		JointServo(int id, Communication *comm);
		JointServo();

		int setJointMode(bool wheelMode);
		int setStep(int step, int speed);
		int setSpeed(int speed);

	private:
		bool port;

};

#endif /* JOINTSERVO_H_ */
