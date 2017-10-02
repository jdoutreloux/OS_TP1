all : serveur client

serveur : serveur.c serveur.h
	gcc -Wall -Werror -std=c99 -D_SVID_SOURCE -o serveur serveur.c serveur.h

client : client.c serveur.h
	gcc -Wall -Werror -std=c99 -D_SVID_SOURCE -o client client.c client.h

clean : 
	rm -rf serveur client
