#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h> 
#include <string.h>    
#include <sys/socket.h>    
#include <arpa/inet.h> 
#include <stdlib.h>
#include <mutex>
#include <queue>
#include <string>
#include "definitions.h"

extern "C" 
{
	int connectUDP();
	void listenUDP(struct TemperatureStruct *temperatureStruct);
}


#endif