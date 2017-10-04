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
    msgId = msgget(10,0666); //msgget returns the message queue identifier
	
	struct data * dc= (struct data*) malloc(sizeof(struct data)); //creation de la structure data (int : pid et char[] : filename)
	strcpy(dc->filename, argv[1]); //place dans la data le nom du fichier passe en argument
	
	struct receive* rcv = (struct receive*) malloc(sizeof(struct receive)); //receive (long mtype, data : msgdata)
	rcv->msgdata = *dc;
	rcv->mtype =1;
	
	if (rcv->msgdata.filename != NULL) {
		rcv->msgdata.pid = getpid();
		int i = msgsnd(msgId, rcv,sizeof(argv), 0666);
		
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
	else{printf("erreur, msgdata.filename == NULL\n");}
	
	int finish = 0; //file finish, pas communication 0 pas fini, 1 fini
	FILE *f = fopen("sortie", "w");
	if(!f){
    fprintf(stderr,"can't open\n");
    return 1;
	}
	struct send* snd = (struct send*) malloc(sizeof(struct send));
	int count = 0;
	while(finish == 0)
	{
		//snd = (struct send*) malloc(sizeof(struct send));
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
				printf("finish, EOF \n");
				finish = 1;
			}
		}
		printf("fin for\n");
		printf("count = %d\n",count);
		
	}
	free(snd);
	fclose(f);

	
	
}


