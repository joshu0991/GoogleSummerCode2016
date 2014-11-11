/*
 * Server_Implimentation.cpp
 *
 *  Created on: Oct 24, 2014
 *      Author: sputnik-110
 */

#include "Server.hpp"

mainServer::mainServer() : port("5555")
{
	 	//int socket(int domain, int type, int protocol);
		struct addrinfo host_info;       // The struct that getaddrinfo() fills up with data.
		struct addrinfo *host_info_list; // Pointer to the to the linked list of host_info's.


		std::cout << "Gathering host information" << std::endl;
 		memset(&host_info, 0, sizeof host_info);
		host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
		host_info.ai_socktype = SOCK_STREAM; // Use SOCK_STREAM for TCP or SOCK_DGRAM for UDP.

		std::cout << "Setting socket" << std::endl;
		socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype, host_info_list->ai_protocol);
		std::cout << "Socket set successfully" << std::endl;
		if(socketfd <= 0) std::cout << "Error creating socket " << std::endl;
		host_info.ai_flags = AI_PASSIVE;
		std::cout << "socket discriptor set" << std::endl;


		status = getaddrinfo(NULL, port, &host_info, &host_info_list);
		std::cout << "Binding socket... " << std::endl;
		int yes = 1;
		status = setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));//check if in use
		status = bind(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
		if (status == -1)  std::cout << "bind error" << std::endl;
		std::cout << "Listen()ing for connections..."  << std::endl;
		//status = listen(socketfd, 2);
		if (status == -1)  std::cout << "listen error" << std::endl ;
		struct sockaddr_storage their_addr;
		socklen_t addr_size = sizeof(their_addr);
		new_sd = accept(socketfd, (struct sockaddr *)&their_addr, &addr_size);


}

char* mainServer::getPort()
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
	std::cout << "Waiting to recieve data..."  << std::endl;
	ssize_t bytes_recieved;
	char incomming_data_buffer[1000];
	bytes_recieved = recv(new_sd, incomming_data_buffer,1000, 0);

}

int mainServer::handleInput(void)
{

}
