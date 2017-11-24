#include "messageHandler.h"

using namespace std;

void msgHandler(char *msgRecv, struct TemperatureStruct *TemperatureStruct)
{

	string msgRecvString = string(msgRecv);
	string msgHeader = msgRecvString.substr(0, 3);

	cout << msgHeader << endl;

	if (msgHeader == string("$01"))
	{
		cout << 1 << endl;
	}

	if (msgHeader == string("$02"))
	{
		cout << 2 << endl;
	}

}