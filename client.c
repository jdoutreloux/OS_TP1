#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "serveur.h"

int main( int argc, const char* argv[] )
{
        int msgId;
        msgId = msgget(10,0666);
	
	struct data * dc= (struct data*) malloc(sizeof(struct data));
	strcpy(dc->filename, argv[0]);

	struct receive* rcv = (struct receive*) malloc(sizeof(struct receive));
	rcv->msgdata = *dc;
	rcv->mtype =1;

        //const void *filename = argv[0];
	if (rcv->msgdata.filename != NULL) {
		rcv->msgdata.pid = getpid();
		int i = msgsnd(msgId, rcv,sizeof(argv), 0666);
		if(i==0)
		{
			//success
			printf("blabl1\n");
			printf("%d maaarrre", argc);
			
			printf("%s",argv[0]);
		}
		else
		{
			printf("blabla\n");
		}
	}
	
	struct send* snd = (struct send*) malloc(sizeof(struct send));

	msgrcv(msgId,  snd,sizeof(snd),getpid(),0666);
}


