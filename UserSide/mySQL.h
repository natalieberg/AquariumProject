#ifndef MYSQL_H_
#define MYSQLR_H_

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <mutex>
#include <queue>
#include "definitions.h"


void uploadSQL(struct TemperatureStruct *TemperatureStruct);

#endif 