
#include "client.h"
 
int connectUDP()
{
    int sock;
    struct sockaddr_in server;
     
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
     
    server.sin_addr.s_addr = inet_addr("129.241.154.25");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
 
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
    }

    puts("Connected\n");

    return sock;
}
     
void listenUDP(int sock)
{
    char server_reply[2000];
    while(1)
    {       
        //Receive a reply from the server
        if( recv(sock , server_reply , 2000 , 0) < 0)
        {
            puts("recv failed");
            break;
        }
         
        puts("Message from server:");
        puts(server_reply);
    }
}

