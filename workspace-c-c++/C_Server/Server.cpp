/*
 * Server.cpp
 *
 *  Created on: Oct 18, 2014
 *      Author: sputnik-110
 */
#include "Main_Server.hpp"

void Server::error(char* message)
{
	perror(message);
	exit(1);
}

int Server::serv_accept()
{
	//set up a new socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		error("Could not open socket");
	}
	//set buffer to contain all zeros
	bzero((char*) &serv_addr, sizeof(serv_addr));
	//alwalys set sin family to AF_INET
	serv_addr.sin_family = AF_INET;
	//htons converts host byte order to network byte order
	serv_addr.sin_port = htons(portno);
	//get the server ip address which is the the host IP IANDDR_ANY gets address
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	//bind the socket
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
	  error("ERROR on binding");
	}
	//listen on the socket file descriptor, 5 is the max number of connectiosn that
	//can be pending in the queue
	listen(sockfd,5);
	//get size of the clilen and accept a new conenction
	socklen_t clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0)
	  error("ERROR on accept");
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////

void Server::setPortno(char* pNum)
{

	int num = atoi(pNum);
	this->portno = num;

}

//////////////////////////////////////////////////////////////////////////////////

int Server::getPortNum()
{

	return this->portno;

}

////////////////////////////////////////////////////////////////////////////////////


//notes:
/*
*structure format
* struct sockaddr_in
*	{
* short   sin_family; // must be AF_INET
*  u_short sin_port;
*  struct  in_addr sin_addr;
* char    sin_zero[8]; // Not used, must be zero
*	};
*/
