/*
 * Server.hpp
 *
 *  Created on: Oct 24, 2014
 *      Author: sputnik-110
 */

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <iostream>
#include <string>

class mainServer
{
	int port = 5555;

public:
	void setPort(char*);
	int getPort();
};



#endif /* SERVER_HPP_ */
