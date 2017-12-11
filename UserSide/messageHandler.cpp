#include "messageHandler.h"

using namespace std;

void msgHandler(char *msgRecv, struct TemperatureStruct *temperatureStruct,
	struct PHStruct *phStruct, struct LeakStruct *leakStruct)
{
	string temperatureString;
	float temperature;
	string phString;
	float ph;
	string leakString;
	bool leak;
	string msgRecvString = string(msgRecv);
	string msgHeader = msgRecvString.substr(0, 3);

	//cout << "Msg recv: " << msgRecvString << endl;
	//cout << "Header: " <<  msgHeader << endl;

	if (msgHeader == string("$01"))
	{
		temperatureString = msgRecvString.substr(3);
		temperature = stof(temperatureString);
		cout << "Temperature(C): " << temperature << endl;
		temperatureStruct->temperatureMutex.lock();
		temperatureStruct->temperatureQ.push(temperature);
		temperatureStruct->temperatureMutex.unlock();
	}

	if (msgHeader == string("$02"))
	{
		phString = msgRecvString.substr(3);
		ph = stof(phString);
		cout << "pH: " << ph << endl;
		phStruct->phMutex.lock();
		phStruct->phQ.push(ph);
		phStruct->phMutex.unlock();

	}

		if (msgHeader == string("$03"))
	{
		leakString = msgRecvString.substr(3);
		leak = stoi(leakString);
		cout << "Leak: " << leak << endl;
		leakStruct->leakMutex.lock();
		leakStruct->leakQ.push(leak);
		leakStruct->leakMutex.unlock();
	}

}