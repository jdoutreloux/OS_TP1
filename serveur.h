struct data{

int pid;
char filename[100];


};

struct receive{

long mtype;
struct data msgdata;
};

struct send{

long type;
char texte[1000]
};

