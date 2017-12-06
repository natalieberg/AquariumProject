#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include "definitions.h"

void msgHandler(char *msgRecv, struct TemperatureStruct *temperatureStruct,
	struct PHStruct *phStruct, struct LeakStruct *leakStruct);

#endif