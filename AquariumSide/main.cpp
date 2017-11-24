#include <thread>
#include <queue>
#include <mutex>
#include "server.h"
#include "readTemp.h"
#include "detectLeak.h"
#include "definitions.h"

using namespace std;


int main()
{

	TemperatureStruct temperatureStruct = {.temperature = 0};
	ConnectionStruct connectionStruct = {.isConnected = false};
	LeakStruct leakStruct = {.isLeaking = false};


	thread serverThread (sendUDP, &connectionStruct, &temperatureStruct, &leakStruct);
	thread temperatureThread (readTemp, &temperatureStruct);
	thread leakThread(detectLeak, &leakStruct);

	serverThread.join();
	temperatureThread.join();
	leakThread.join();

	return 0;
}