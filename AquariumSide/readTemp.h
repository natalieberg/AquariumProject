#ifndef READTEMP_H_
#define READTEMP_H_

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
#include "definitions.h"

void readTemp(struct TemperatureStruct *temperaturStruct);

#endif