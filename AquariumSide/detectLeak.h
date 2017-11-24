#ifndef DETECTLEAK_H_
#define DETECTLEAK_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <mutex> 
#include "/home/natalie/wiringPi/wiringPi/wiringPi.h"
#include "definitions.h"

void detectLeak(struct LeakStruct *leakage);


#endif


