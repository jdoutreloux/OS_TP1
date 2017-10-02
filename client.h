#ifndef CLIENT
#define CLIENT

typedef struct data{

int pid;
char filename[100];


} data;

typedef struct receive{

long mtype;
struct data msgdata;
} receive;

#endif

