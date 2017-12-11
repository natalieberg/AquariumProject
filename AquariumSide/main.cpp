#include <thread>
#include <queue>
#include <mutex>
#include "server.h"
#include "readTemp.h"
#include "detectLeak.h"
#include "readPH.h"
#include "pump.h"
#include "definitions.h"

using namespace std;


int main()
{

	TemperatureStruct temperatureStruct = {.temperature = 0};
	PHStruct phStruct = {.ph = 0};
	LeakStruct leakStruct = {.isLeaking = false};
	ConnectionStruct connectionStruct = {.isConnected = false};


	thread serverThread (sendUDP, &connectionStruct, &temperatureStruct, 
		&phStruct, &leakStruct);
	thread temperatureThread (readTemp, &temperatureStruct);
	thread phThread (readPH, &phStruct);
	thread leakThread(detectLeak, &leakStruct);
	thread pumpThread(pumpControl);

	serverThread.join();
	temperatureThread.join();
	phThread.join();
	leakThread.join();
	pumpThread.join();

	return 0;
}