#include "serveur.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "serveur.h"

int main( int argc, const char* argv[] )
{
        int msgId;
        msgId = msgget(10,0666);

        *msg //creer variable pour stocker le message
        //    creer la structure pour le message client
        //    //gerer pour le while true
        //    msgrcv(msgId,  msg,sizeof(struct...),1,0666);
        //    *answer //creer message reponse
        //    int i = msgsnd(msgId, answer, sizeof(answer), 0666);
}
