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

#define SERVER "localhost:3306"
#define USERNAME "root"
#define PASSWORD "root"
#define DATABASE "AquaruimDatabase"

using namespace std;

int main(void){

        sql::Driver *driver;
        sql::Connection *conn;
        sql::Statement *statemnt;
        sql::ResultSet *res;

    try {

        /* Create a connection */
        driver = get_driver_instance();
        conn = driver->connect(SERVER, USERNAME, PASSWORD);

        /* Connect to the MySQL test database */
        conn->setSchema("Aquarium");

        statemnt = conn->createStatement();
        statemnt->execute("CREATE TABLE IF NOT EXISTS Temperature");

        /* '?' is the supported placeholder syntax */
        statemnt = conn->prepareStatement("INSERT INTO Temperature(id) VALUES (?)");
        for (int i = 1; i <= 10; i++) {
            statemnt->setInt(1, i);
            statemnt->executeUpdate();
        }



        delete res;
        delete pstmt;
        delete con;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;

    return 0;
}