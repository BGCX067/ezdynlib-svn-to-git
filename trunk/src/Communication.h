/*
 * Communication.h
 *
 *  Created on: 13. okt. 2011
 *      Author: Lars
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

class Communication {
public:
	Communication();
	virtual ~Communication();
	int connect();
	void disconnect();
	int sendCommand(int id, int address, int value);
	int getInfo(int id, int address);
	std::string getResultErrorMsg(int result);
	bool ping(int id);
};

#endif /* COMMUNICATION_H_ */
