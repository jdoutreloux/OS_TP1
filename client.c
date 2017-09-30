#include "client.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "serveur.h"

int main( int argc, const char* argv[] )
{
        int msgId;
        msgId = msgget(10,0666);

        const void *filename = argv[0];
	int i = msgsnd(msgId, filename,sizeof(filename), 0666);

	msgrcv(msgId,  msg,sizeof(...),1,0666);
}
