#ifndef CLIENT_H
#define CLIENT_H

#include<stdio.h> 
#include<string.h>    
#include<sys/socket.h>    
#include<arpa/inet.h> 

extern "C" 
{
	int connectUDP();
	void listenUDP(int sock);
}


#endif