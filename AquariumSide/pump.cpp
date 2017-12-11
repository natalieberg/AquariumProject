#include "pump.h"

using namespace std;

void pumpControl()
{
	wiringPiSetup();
	pinMode(1, OUTPUT);
	digitalWrite(1,1);
	string pumpCommand;

	while(1)
	{
		cout << "Type in pump command" << endl; 
		getline (cin, pumpCommand);

		if (pumpCommand == string("pump on"))
		{
			cout << "Turning pump on" << endl;
			digitalWrite(1, 0);

		} else if (pumpCommand == string("pump off"))
		{
			cout << "Turning pump off" << endl;
			digitalWrite(1, 1);
		}

		sleep(1);
	}
}