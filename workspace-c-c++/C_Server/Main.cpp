/*
 * Main.cpp
 *
 *  Created on: Oct 18, 2014
 *      Author: sputnik-110
 */



#include "Main_Server.hpp"

int main(int argc, char* argv[])
{

	Server s;
	std::cout << "Server started" << std::endl;
	if(argc >= 2 )
	{
		s.setPortno(argv[2]);
	}

	std::cout << "Running on port " << s.getPortNum() <<std::endl;
	//loop forever
	while(true)
	{
		s.serv_accept();
	}
	return 0;

}
