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
	printf("%s 1 \n",argv[0]);
        int msgId;
        msgId = msgget(10,0666);
	
	struct data * dc= (struct data*) malloc(sizeof(struct data));
	strcpy(dc->filename, argv[1]);
	printf("%s 2 %s\n",argv[0], dc->filename);
	
	struct receive* rcv = (struct receive*) malloc(sizeof(struct receive));
	rcv->msgdata = *dc;
	rcv->mtype =1;
	
	printf("%s 3 \n",argv[0]);

        //const void *filename = argv[0];
	if (rcv->msgdata.filename != NULL) {
		rcv->msgdata.pid = getpid();
		int i = msgsnd(msgId, rcv,sizeof(argv), 0666);
		//printf("%s 4 \n",argv[0]);
		
		if(i==0)
		{
			//success
			printf("i==0\n");
		}
		else
		{
			printf("i!=0\n");
		}
	}
	
	
	int finish = 0; //file finish, pas communication 0 pas fini, 1 fini
	FILE *f = fopen("sortie", "w");
	struct send* snd;
	int count = 0;
	while(finish == 0)
	{
		snd = (struct send*) malloc(sizeof(struct send));
		count++;
		printf("debut while\n");
		msgrcv(msgId,  snd,sizeof(snd),getpid(),0666);
		printf("sizeof(snd) : %li\n", sizeof(snd));
		printf("sizeof(receiver) : %li\n", sizeof(struct receive));
		
		
		if (f == NULL){
			printf(" f NULL\n");
			return 1;}
		else {printf(" F non NULL\n");}
		int charac;
		for (int i=0; i<1000 || finish == 0; i++){
			charac=  fputc( snd->texte[i], f );
			printf("%c",(char)charac);
			if(snd->texte[i]== EOF)
			{
				finish = 1;
			}
		}
		printf("fin for\n");
		printf("%d\n",count);
		
	}
	free(snd);
	fclose(f);

	
	
}


