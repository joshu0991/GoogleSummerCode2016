/*
 * Main_Server.hpp
 *
 *  Created on: Oct 18, 2014
 *      Author: sputnik-110
 */

#ifndef MAIN_SERVER_HPP_
#define MAIN_SERVER_HPP_
#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

class Server
{

	int portno = 5555;
	int sockfd, newsockfd, clilen, n;
	struct sockaddr_in serv_addr;
	struct sockaddr_storage cli_addr;
public:
	void error(char* message);
	int serv_accept();
	void setPortno(char*);
	int getPortNum();
	//int write();
	//int read();
};
#endif /* MAIN_SERVER_HPP_ */
