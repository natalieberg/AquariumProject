#include "mySQL.h"

#define SERVER "localhost:3306"
#define USERNAME "root"
#define PASSWORD "root"
#define DATABASE "AquariumDatabase"

using namespace std;

void uploadSQL(struct TemperatureStruct *temperatureStruct, struct PHStruct *phStruct,
    struct LeakStruct *leakStruct)
{

        sql::Driver *driver;
        sql::Connection *conn;
        sql::Statement *statemnt;
        sql::PreparedStatement *preparedStatemnt;


    try {

        /* Create a connection */
        driver = get_driver_instance();
        conn = driver->connect(SERVER, USERNAME, PASSWORD);

        /* Connect to the MySQL test database */
        conn->setSchema(DATABASE);

        statemnt = conn->createStatement();
        statemnt->execute("CREATE TABLE IF NOT EXISTS Temperature (temperature FLOAT, \
            timestamp TIMESTAMP)");

        statemnt->execute("TRUNCATE TABLE Temperature");


        statemnt->execute("CREATE TABLE IF NOT EXISTS pH (ph FLOAT, \
            timestamp TIMESTAMP)");

        statemnt->execute("TRUNCATE TABLE pH");


        statemnt->execute("CREATE TABLE IF NOT EXISTS Leakage (leak BIT, \
            timestamp TIMESTAMP)");

        statemnt->execute("TRUNCATE TABLE Leakage");




        while(1)
        {
            preparedStatemnt = conn->prepareStatement("INSERT INTO Temperature (temperature) VALUES (?)");
            temperatureStruct->temperatureMutex.lock();
            if (!(temperatureStruct->temperatureQ.empty()))
            {
                preparedStatemnt->setDouble(1, temperatureStruct->temperatureQ.front());
                temperatureStruct->temperatureQ.pop();
                preparedStatemnt->executeUpdate();
            }
            temperatureStruct->temperatureMutex.unlock();

            preparedStatemnt = conn->prepareStatement("INSERT INTO pH (ph) VALUES (?)");
            phStruct->phMutex.lock();
            if(!(phStruct->phQ.empty()))
            {
                preparedStatemnt->setDouble(1, phStruct->phQ.front());
                phStruct->phQ.pop();
                preparedStatemnt->executeUpdate();
            }
            phStruct->phMutex.unlock();

            preparedStatemnt = conn->prepareStatement("INSERT INTO Leakage (leak) VALUES (?)");
            leakStruct->leakMutex.lock();
            if (!(leakStruct->leakQ.empty()))
            {
                preparedStatemnt->setDouble(1, leakStruct->leakQ.front());
                leakStruct->leakQ.pop();
                preparedStatemnt->executeUpdate();
            }
            leakStruct->leakMutex.unlock();

            sleep(5);
        }


        delete conn;

    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}