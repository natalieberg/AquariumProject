#include <functional>
#include <thread>  
#include "client.h"
#include "mySQL.h"
#include "messageHandler.h"
#include "definitions.h"

using namespace std;

int main()
{

	TemperatureStruct temperatureStruct;
	ConnectionStruct connectionStruct = {.isConnected = false};
	//MessageStruct msgStruct;

	thread listenUDPThread (listenUDP, &temperatureStruct);
	//thread msgHandlerThread(msgHandler, &msgStruct);
	//thread sqlThread (uploadSQL, &temperatureStruct);

	listenUDPThread.join();
	//msgHandlerThread.join();
	//sqlThread.join();

	return 0;
}
