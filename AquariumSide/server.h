#include <stdio.h>
#include <string.h>    
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <condition_variable>
#include <mutex>
#include <queue>

extern "C"
{
    int serverInit(bool *connectionStatus, std::mutex *connectionMutex);
    void sendUDP(std::queue<float> *temperatureQueue, std::mutex *temperatureMutex, 
    	bool *connectionStatus, std::mutex *connectionMutex);	
}