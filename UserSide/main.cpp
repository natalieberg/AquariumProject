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
	PHStruct phStruct;
	LeakStruct leakStruct;
	ConnectionStruct connectionStruct = {.isConnected = false};

	thread listenUDPThread (listenUDP, &temperatureStruct, &phStruct, &leakStruct);
	thread sqlThread (uploadSQL, &temperatureStruct, &phStruct, &leakStruct);

	listenUDPThread.join();
	sqlThread.join();

	return 0;
}
