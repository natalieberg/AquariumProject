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
    int serverInit();
    void sendUDP(std::queue<float> *temperatureQueue);	
}