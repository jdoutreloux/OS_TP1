#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include "serveur.h"

int main( int argc, const char* argv[] )
{
        int msgId;
        msgId = msgget(10,0666);
	
	struct data * dc= (struct data*) malloc(sizeof(struct data));
	dc.filename = argv[0];

	struct receive* rcv = (struct receive*) malloc(sizeof(struct receive));
	rcv->msgdata =dc;
	rcv->mtype =1;

        //const void *filename = argv[0];
	if (rcv->msgdata != NULL) {
		int i = msgsnd(msgId, rcv,sizeof(filename), 0666);
	}

	msgrcv(msgId,  msg,sizeof(...),1,0666);
}


