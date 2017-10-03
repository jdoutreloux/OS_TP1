#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>
#include "serveur.h"
#include <stdlib.h>

int main( int argc, const char* argv[] )
{
	int msgId;
	msgId = msgget(10,IPC_CREAT|0666);
	struct receive *msg = (struct receive*)malloc(sizeof(struct receive));
	if(msg==NULL){
		printf("Error. Allocation was unsuccessful. \n");
		return 1;
	}
	struct data d; //creer la structure pour le message client
	//gerer pour le while true
	printf("hello\n");
	msgrcv(msgId, msg,sizeof(msg),1,0);
	d = msg->msgdata;
	printf("hello1\n");

	struct send* answer = (struct send*)malloc(sizeof(struct send)); //creer message reponse
	if(answer==NULL){
    printf("Error. Allocation was unsuccessful. \n");
    return 1;
	}
	answer->type = d.pid;
	printf("hello2\n");
	FILE *f = fopen(d.filename, "r");
	printf("hello3\n");
	printf("%s d.filename \n",d.filename);
	if (f == NULL){
		printf("hello f NULL\n");
		return 1;}
	else {printf("hello F non NULL\n");}
	int i;
	if(f)
	{
		printf("hello4\n");
		fseek (f, 0, SEEK_END);
		long length = ftell (f);
		fseek (f, 0, SEEK_SET);
		while(length>0)
		{
			printf("hello5\n\n\n\n\n");
			if(length>1000)
			{
				printf("hellolength>\n");
				fread(answer->texte, sizeof(char), 1000, f);
				length = length - 1000; //?
				printf("LENGTH ICI %li",length);
				for (int i=0; i < 1000; i++){//printf("%c",answer->texte[i]);
					}
				i = msgsnd(msgId, answer,sizeof(answer), 0666);
			}
			else
			{
				printf("hellolength<\n");
				fread(answer->texte, sizeof(char), length, f);
				for (int i=0; i < length; i++){//printf("%c",answer->texte[i]);
					}
				length = 0;
				i = msgsnd(msgId, answer,sizeof(answer), 0666);
			}
		}
		fclose(f);
		if(i==0)
		{
			printf("success\n");
			//successful
		}
		else
		{
			//error
		}
	}
	
	
}

