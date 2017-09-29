#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "serveur.h"

int main( int argc, const char* argv[] )
{
	int msgId;
	msgId = msgget(10,0666);
	
	struct receive msg; //creer variable pour stocker le message
	struct data d; //creer la structure pour le message client
	//gerer pour le while true
	msgrcv(msgId,  msg,sizeof(struct...),1,0666);
	d = msg->data;
	struct receive* answer; //creer message reponse
	answer->type = data->pid;
	//answer->  2e structure message?
	int i = msgsnd(msgId, answer, sizeof(answer), 0666);
	
	
}
