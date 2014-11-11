/*
 * Main.cpp
 *
 *  Created on: Oct 24, 2014
 *      Author: sputnik-110
 */

#include "Server.hpp"

int main(int argc, char** argv)
{
	//mainServer mS;
	std::cout << "Starting server " << std::endl;
	mainServer* mS;
	mS = new mainServer();
	if(mS == 0)
	{
		std::cout << "Starting server failed" << std::endl;
	}

	if(argc == 2)
	{
		mS->setPort(argv[1]);
	}
	else
	{
		perror("Error the server was not provided a port");
		exit(0);
	}

	std::cout << "Running on port " << mS->getPort() << std::endl;
	//while(true)
	//{
	//	mS->listen();
	//}
	delete(mS);
	mS = 0;
	std::cout << "Memory deleted" << std::endl;
	return 0;
}
