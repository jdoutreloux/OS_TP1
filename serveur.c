#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>
#include "serveur.h"
#include <stdlib.h>

int main( int argc, const char* argv[] )
{
	int msgId;
	msgId = msgget(10,0666);
	struct receive *msg = (struct receive*)malloc(sizeof(struct receive));
	if(msg==NULL){
		printf("Error. Allocation was unsuccessful. \n");
		return 1;
	}
	struct data d; //creer la structure pour le message client
	//gerer pour le while true
	msgrcv(msgId, msg,sizeof(msg),1,0);
	d = msg->msgdata;
	struct send* answer = (struct send*)malloc(sizeof(struct send)); //creer message reponse
	if(answer==NULL){
    printf("Error. Allocation was unsuccessful. \n");
    return 1;
	}
	answer->type = d.pid;
	FILE *f = fopen(d.filename, "r");
	int i;
	if(f)
	{
		fseek (f, 0, SEEK_END);
		long length = ftell (f);
		fseek (f, 0, SEEK_SET);
		while(length>0)
		{
			if(length>1000)
			{
				fread(answer->texte, sizeof(char), 1000, f);
				length = length - 1000; //?
				i = msgsnd(msgId, answer,sizeof(answer), 0666);
			}
			else
			{
				fread(answer->texte, sizeof(char), length, f);
				length = 0;
				i = msgsnd(msgId, answer,sizeof(answer), 0666);
			}
		}
		fclose(f);
		if(i==0)
		{
			//successful
		}
		else
		{
			//error
		}
	}
	
	
}

