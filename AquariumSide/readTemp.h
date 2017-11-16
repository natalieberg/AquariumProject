#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <mutex>

void readTemp(std::queue<float> *temperatureQueue, std::mutex *temperatureMutex,
	bool *connectionStatus, std::mutex *connectionMutex);