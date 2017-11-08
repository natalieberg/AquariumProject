#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fstream>

#define BUFFER_SIZE 40

using namespace std;

int main()
{
    FILE *fp;
    char buff[BUFFER_SIZE];
    string dir = "/sys/bus/w1/devices/28-0417005b62ff";

    system("modprobe w1-gpio");
    system("modprobe w1-therm");

    chdir(dir.c_str());

    fp = popen("cat w1_slave", "r");

    if (fp != NULL)
    {
        while (fgets(buff, BUFFER_SIZE, fp) != NULL)
        {
            printf("%s", buff);
        }

        pclose(fp);
    }
        

  return 0;

}