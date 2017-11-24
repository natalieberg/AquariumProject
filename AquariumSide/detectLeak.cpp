#include "detectLeak.h"

using namespace std;

void detectLeak(struct LeakStruct *leakStruct){

	wiringPiSetup();
	pinMode(0, INPUT);

	while(1){
		leakStruct->leakMutex.lock();
		leakStruct->isLeaking =  !digitalRead(0);
		leakStruct->leakMutex.unlock();

		cout << "isLeaking: " << leakStruct->isLeaking << endl;

		sleep(5);
	}
}