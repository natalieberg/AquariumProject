#include <functional>
#include <thread>  
#include "client.h"

using namespace std;

int main()
{
	int sock;
	
	sock = connectUDP();

	thread listenUDPThread (listenUDP, sock);

	listenUDPThread.join();

	return 0;
}
