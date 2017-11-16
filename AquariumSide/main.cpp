#include <thread>
#include <queue>
#include <mutex>
#include "server.h"
#include "readTemp.h"

using namespace std;

int main()
{

	mutex temperatureMutex;
	mutex connectionMutex;
	bool connectionStatus = false;

	queue<float> temperatureQueue;

	thread serverThread (sendUDP, &temperatureQueue, &temperatureMutex, &connectionStatus, &connectionMutex);
	thread temperatureThread (readTemp, &temperatureQueue, &temperatureMutex, &connectionStatus, &connectionMutex);

	serverThread.join();
	temperatureThread.join();

	return 0;
}