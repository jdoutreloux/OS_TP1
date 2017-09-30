Os tp1

Le client demande un fichier au serveur 
Le serveur envoie le fichier.

On ne connaît ni le nombre de clients ni la taille des fichiers.
Les clients et le serveur communiquent via message queue.

Le serveur est lancé en premier, il crée la mq puis fait un msgrcv en
attendant la demande du client.

Le client fait un msgget pour recevoir la message queue et puis fait un msgsend
et puis un msgrcv.


Attention : msgtype = 1 si on envoie au serveur sinon = id clients 
Data est une structure avec le pid du client et un char [] filename

un fichier c termine toujours par une ligne vide pour aider à la compilation.
