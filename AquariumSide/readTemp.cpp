#include "readTemp.h"

#define BUFFER_SIZE 40
#define TEMPERATURE_SIZE 5

using namespace std;


void readTemp(std::queue<float> *temperatureQueue, std::mutex *temperatureMutex, 
    bool *connectionStatus, std::mutex *connectionMutex)
{
    FILE *fp;
    char buff[BUFFER_SIZE];
    string dir = "/sys/bus/w1/devices/28-0417005b62ff";
    bool validReading = false;
    string validString = "YES";
    string temperatureString = "t=";
    char temperatureBuff[TEMPERATURE_SIZE];
    string buffString;
    size_t pos;
    size_t len;
    int temperature;

    system("modprobe w1-gpio");
    system("modprobe w1-therm");

    chdir(dir.c_str());

    while(1)
    {
        fp = popen("cat w1_slave", "r");
        if (fp != NULL) 
        {
            while (fgets(buff, BUFFER_SIZE, fp) != NULL)
            {   
                buffString = buff;

                if (buffString.find(validString) != string::npos)
                {
                    validReading = true;
                }

                pos = buffString.find(temperatureString);

                if (validReading && pos != string::npos)
                {
                    len = buffString.copy(temperatureBuff, 5, pos+2);
                    temperatureBuff[len] ='\0';
                    //cout << "temp char: " << temperatureBuff << endl;
                    validReading = false;
                    temperature = atoi(temperatureBuff);
                    cout << "temp: " << temperature << endl;
                    connectionMutex->lock();
                    if (*connectionStatus)
                    {
                        temperatureMutex->lock();
                        temperatureQueue->push(temperature);
                        temperatureMutex->unlock();
                    } else {
                        temperatureMutex->lock();
                        while(!temperatureQueue->empty())
                        {
                            temperatureQueue->pop();
                        }
                        temperatureMutex->unlock();
                    }
                    connectionMutex->unlock();
                }

            }

            pclose(fp);
        }

        sleep(1);
        //cout << *connectionStatus << endl;
    }    

}