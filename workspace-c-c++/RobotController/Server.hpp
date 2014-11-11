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
#include <iostream>
#include <cstring>      // Needed for memset
#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include <stdlib.h>

class mainServer
{
	char* port;
	int status;
	struct addrinfo host_info;       // The struct that getaddrinfo() fills up with data.
	struct addrinfo *host_info_list; // Pointer to the to the linked list of host_info's.
	int socketfd;
	int new_sd;

public:
	mainServer();
	void setPort(char*);
	char* getPort();
	int listen();
	//handle input write to file input and send to client received data.
	int handleInput();

};



#endif /* SERVER_HPP_ */
