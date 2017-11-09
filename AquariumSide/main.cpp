#include <thread>
#include <queue>
#include <mutex>
#include "server.h"
#include "readTemp.h"
#include "includes.h"

using namespace std;

int main()
{
	queue<float> temperatureQueue;

	thread serverThread (sendUDP, &temperatureQueue);
	thread temperatureThread (readTemp, &temperatureQueue);

	serverThread.join();
	temperatureThread.join();

	return 0;
}