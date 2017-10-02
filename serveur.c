#include <sys/types.h>
#include <sys/msg.h>
#include <stdio.h>
#include "serveur.h"

int main( int argc, const char* argv[] )
{
	int msgId;
	msgId = msgget(10,0666);
	
	struct receive msg; //creer variable pour stocker le message
	struct data d; //creer la structure pour le message client
	//gerer pour le while true
	msgrcv(msgId,  msg,sizeof(msg),1,0666);
	d = msg.msgdata;
	struct send* answer; //creer message reponse
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

