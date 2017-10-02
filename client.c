#include "client.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "serveur.h"

int main( int argc, const char* argv[] )
{
        int msgId;
        msgId = msgget(10,0666);
	
	struct receive* rcv;
	rcv->msgdata =argv[0];
	rcv->mtype =1;

        //const void *filename = argv[0];
	if (rcv->msgdata != NULL) {
		int i = msgsnd(msgId, rcv,sizeof(filename), 0666);
	}

	msgrcv(msgId,  msg,sizeof(...),1,0666);
}


