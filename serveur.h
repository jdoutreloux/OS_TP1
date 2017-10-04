#ifndef _SERVEUR_H
#define _SERVEUR_H


typedef struct data {
int pid;
char filename[100];
}data;

typedef struct receive {

long mtype;
struct data msgdata;
}receive;

typedef struct send {
long type;
char texte[1000];
}send;
#endif


