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
	 //int socket(int domain, int type, int protocol);
	socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype, host_info_list->ai_protocol);
	if(socketfd < 0) std::cout << "Error creating socket " << std::endl;
	host_info.ai_flags = AI_PASSIVE;
	memset(&host_info, 0, sizeof host_info);
	host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
	host_info.ai_socktype = SOCK_STREAM; // Use SOCK_STREAM for TCP or SOCK_DGRAM for UDP.
	status = getaddrinfo(NULL, port, &host_info, &host_info_list);
	std::cout << "Binding socket... " << std::endl;
	int yes = 1;
	status = setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));//check if in use
	status = bind(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
	if (status == -1)  std::cout << "bind error" << std::endl ;
	return 0;
}
