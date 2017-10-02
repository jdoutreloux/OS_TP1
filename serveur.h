#ifndef SOME_HEADER_GUARD_WITH_UNIQUE_NAME
#define SOME_HEADER_GUARD_WITH_UNIQUE_NAME


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
char texte[1000]
}send;
#endif


