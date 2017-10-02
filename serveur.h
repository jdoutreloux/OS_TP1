typedef struct data{

int pid;
char filename[100];


};

typedef struct receive{

long mtype;
struct data msgdata;
};

typedef struct send{

long type;
char texte[1000]
};

