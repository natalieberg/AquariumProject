#include "server.h" 

int socket_desc , client_sock;

int serverInit(struct ConnectionStruct *connectionStruct)
{
    int c;
    struct sockaddr_in server , client;

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

    connectionStruct->connectionMutex.lock();
    connectionStruct->isConnected = true;
    connectionStruct->connectionMutex.unlock();

    return 0;
}

void sendUDP(struct ConnectionStruct *connectionStruct, 
    struct TemperatureStruct *temperatureStruct, 
    struct PHStruct *phStruct, struct LeakStruct *leakStruct)
{
    int errSend;
    char msgTemperature[2000];
    char msgPH[2000];
    char msgLeak[2000];

    serverInit(connectionStruct);

    while(1)
    {   
        temperatureStruct->temperatureMutex.lock();
        sprintf(msgTemperature, "$01 %4.2f \n", temperatureStruct->temperature);
        temperatureStruct->temperatureMutex.unlock();

        phStruct->phMutex.lock();
        sprintf(msgPH, "$02 %4.2f \n", phStruct->ph);
        phStruct->phMutex.unlock();

        leakStruct->leakMutex.lock();
        sprintf(msgLeak, "$03 %d \n", leakStruct->isLeaking);
        leakStruct->leakMutex.unlock();

        printf("%s\n", msgTemperature);
        printf("%s\n", msgPH);
        printf("%s\n", msgLeak);


        //TODO: FIX SERVER DED WHEN CLIENT DISCONNECTS
        errSend = send(client_sock, msgTemperature, strlen(msgTemperature), 0);
        sleep(1);
        errSend = send(client_sock, msgPH, strlen(msgPH), 0);
        sleep(1);
        errSend = send(client_sock, msgLeak, strlen(msgLeak), 0);
        if (errSend == -1)
        {
            close(socket_desc);
            close(client_sock);
            connectionStruct->connectionMutex.lock();
            connectionStruct->isConnected = false;
            connectionStruct->connectionMutex.unlock();
            puts("Connection closed");
            sleep(1);
            serverInit(connectionStruct);
        }

    sleep(3);
    } 
}