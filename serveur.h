typedef struct data data;
struct data{

int pid;
char filename[100];


};

typedef struct receive receive;
struct receive{

long mtype;
struct data msgdata;
};

typedef struct send send;
struct send{

long type;
char texte[1000]
};

