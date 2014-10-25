/*
 * Server_Implimentation.cpp
 *
 *  Created on: Oct 24, 2014
 *      Author: sputnik-110
 */

#include "Server.hpp"


int mainServer::getPort()
{

	return this->port;

}

////////////////////////////////////////////////////////////////////////////////

void mainServer::setPort(char* portNum)
{
	this->port = portNum;
	//this->port = atoi(portNum);
}

////////////////////////////////////////////////////////////////////////////////

int mainServer::listen()
{
	host_info.ai_flags = AI_PASSIVE;
	memset(&host_info, 0, sizeof host_info);
	host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
	host_info.ai_socktype = SOCK_STREAM; // Use SOCK_STREAM for TCP or SOCK_DGRAM for UDP.
	status = getaddrinfo(NULL, port, &host_info, &host_info_list);
	return 0;
}
