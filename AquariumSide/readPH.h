#ifndef READPH_H_
#define READPH_H_

#include <unistd.h>			
#include <fcntl.h>				
#include <sys/ioctl.h>			
#include <linux/i2c-dev.h>	
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <mutex>
#include "definitions.h"


int readPH(struct PHStruct *phStruct);

#endif