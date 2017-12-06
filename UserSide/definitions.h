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

struct PHStruct
{
	std::queue<float> phQ;
	std::mutex phMutex;
};

struct LeakStruct
{
	std::queue<bool> leakQ;
	std::mutex leakMutex;
};

struct ConnectionStruct
{
	bool isConnected;
	std::mutex connectionMutex;
};

#endif