#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

struct TemperatureStruct
{
	float temperature;
	std::mutex temperatureMutex;
};

struct PHStruct
{
	float ph;
	std::mutex phMutex;
};

struct LeakStruct
{
	bool isLeaking;
	std::mutex leakMutex;
};

struct ConnectionStruct
{
	bool isConnected;
	std::mutex connectionMutex;
};

#endif