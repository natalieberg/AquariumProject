#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

struct TemperatureStruct
{
	float temperature;
	std::mutex temperatureMutex;
};

struct ConnectionStruct
{
	bool isConnected;
	std::mutex connectionMutex;
};

struct LeakStruct
{
	bool isLeaking;
	std::mutex leakMutex;
};


#endif