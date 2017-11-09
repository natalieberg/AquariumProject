#include "server.h" 
#include "includes.h"

int socket_desc , client_sock , c , read_size , err_send;
struct sockaddr_in server , client;
char msg[2000];
char msg_received[2000];

int serverInit()
{
      //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    //puts("Socket created");
     
    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
     
    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
   //puts("Bind done");
     
    //Listen
    listen(socket_desc , 3);
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
     
    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0)
    {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");

    return 0;
}

void sendUDP(std::queue<float> *temperatureQueue)
{
    serverInit();

    while(1)
    {
        sprintf(msg, "yoyo");
        err_send = send(client_sock, msg, strlen(msg), MSG_NOSIGNAL);
        if (err_send == -1)
        {
            close(socket_desc);
            close(client_sock);
            puts("Connection closed");
            sleep(1);
            serverInit();
        }
    sleep(1);
    } 
}