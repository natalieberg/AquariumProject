#include "thread"
#include "server.h"

using namespace std;

int main()
{
	serverInit();

	thread sendThread (sendToClient);

	sendThread.join();

	return 0;
}