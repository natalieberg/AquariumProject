#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <string.h>    
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <condition_variable>
#include <mutex>
#include <queue>
#include "definitions.h"

extern "C"
{
    int serverInit(struct TemperatureStruct *temperatureStruct);
    void sendUDP(struct ConnectionStruct *connectionStruct, 
    	struct TemperatureStruct *temperatureStruct, struct PHStruct *phStruct,
    	struct LeakStruct *leakStruct);	
}

#endif