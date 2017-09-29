all : serveur client

serveur : serveur.c serveur.h
	gcc -Wall -Werror -std=c99 -o serveur serveur.c serveur.h

client : client.c serveur.h
	gcc -Wall -Werror -std=c99 -o client client.c serveur.h

clean : rm -f serveur client
