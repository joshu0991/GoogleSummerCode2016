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
	this->port = atoi(portNum);
}

////////////////////////////////////////////////////////////////////////////////
