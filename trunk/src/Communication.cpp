/*
 * Communication.cpp
 *
 *  Created on: 13. okt. 2011
 *      Author: Lars
 */

#include <stdio.h>
#include <iostream>
#include "Communication.h"
#include "dynamixel.h"

Communication::Communication() {

}

int Communication::connect() {
	///////// Open USB2Dynamixel ////////////
	if (dxl_initialize() == 0) {
		std::cout << "Failed to open USB2Dynamixel!\n";
		dxl_terminate();
		return 0;
	}
	std::cout << "Succeed to open USB2Dynamixel!\n";
	return 1;
}

void Communication::disconnect(){
    dxl_terminate();
}

int Communication::sendCommand(int id, int address, int value) {
//	std::cout << "id: " << id << " address: " << address << " value: " << value << std::endl;
	dxl_write_word(id, address, value);
	int result = dxl_get_result();
	std::cout << getResultErrorMsg(result) << std::endl;
//	std::cout << "result:" << result << std::endl;
	return result;
}

int Communication::getInfo(int id, int address) {
	int info = dxl_read_word(id, address);
	int result = dxl_get_result();
	if (result != COMM_RXSUCCESS &&
		result != COMM_TXSUCCESS) {
		std::cout << getResultErrorMsg(result) << std::endl;
		return -1;
	}
	return info;
}

bool Communication::ping(int id){
    dxl_ping(id);
    if(dxl_get_result() == COMM_RXSUCCESS){
        return true;
    }
    return false;
}

std::string Communication::getResultErrorMsg(int result) {
	switch (result) {
		case COMM_TXSUCCESS:
			return "COMM_TXSUCCESS";
			break;
		case COMM_RXSUCCESS:
			return "COMM_RXSUCCESS";
			break;
		case COMM_TXFAIL:
			return "COMM_TXFAIL";
			break;
		case COMM_RXFAIL:
			return "COMM_RXFAIL";
			break;
		case COMM_TXERROR:
			return "COMM_TXERROR";
			break;
		case COMM_RXWAITING:
			return "COMM_RXWAITING";
			break;
		case COMM_RXTIMEOUT:
			return "COMM_RXTIMEOUT";
			break;
		case COMM_RXCORRUPT:
			return "COMM_RXCORRUPT";
			break;
		default:
			break;
			return "No error msg found";
	}
}

Communication::~Communication() {
	// TODO Auto-generated destructor stub
}

