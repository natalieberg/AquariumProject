#include<stdio.h>
#include<string.h>    
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

extern "C"
{
    int serverInit();
    void sendToClient();	
}