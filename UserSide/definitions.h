#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#include <queue>
#include <mutex>
#include <string>

struct TemperatureStruct
{
	std::queue<float> temperatureQ;
	std::mutex temperatureMutex;
};

struct LeakStruct
{
	std::queue<bool> msgQ;
	std::mutex msgMutex;
};

struct ConnectionStruct
{
	bool isConnected;
	std::mutex connectionMutex;
};

#endif