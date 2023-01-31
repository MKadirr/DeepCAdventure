#include "../../include/host.h"

#include <string.h>



void* accueil(int socketServer, struct Player* Players)
{
	struct sockaddr_in addrClient;
	int csize = sizeof(addrClient);


	for(int i = 0; i < MAX_PLAYER; i++)
	{
		Players[i].socket = accept(socketServer, (struct sockaddr *)&addrClient, &csize);
		


		for(int k = 0; i < 7; i++)
        for(int j = 0; j < 4; j++)
            Players[i].inv[k][j] = 0;
		printf("New Player: \n");
	}
}


int main(int argc, char** argv)
{
    if(argv < 2)
        printf("No ip given, aborted...");
        exit(EXIT_FAILURE);

    struct Player Players[MAX_PLAYER];
    for(int i = 0; i < MAX_PLAYER; i++)
    {
        Players->socket = -1;
    }

    int socketServer = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addrServer;
	addrServer.sin_addr.s_addr = inet_addr(argv[1]);
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(BASE_PORT);

    bind(socketServer, (const struct sockaddr *)&addrServer, sizeof(addrServer));
	printf("bind : %d\n", socketServer);

    listen(socketServer, 5);
	printf("listen\n");

	



    close(socketServer);
	printf("close\n");

	printf("test\n");
	return 0;
}

/*
	int socketServer = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addrServer;
	addrServer.sin_addr.s_addr = inet_addr("127.0.0.1");
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(30000);

	

	bind(socketServer, (const struct sockaddr *)&addrServer, sizeof(addrServer));
	printf("bind : %d\n", socketServer);


	listen(socketServer, 5);
	printf("listen\n");



	struct sockaddr_in addrClient;
	int csize = sizeof(addrClient);
	int socketClient = accept(socketServer, (struct sockaddr *)&addrClient, &csize);
	printf("accept\n");

	printf("client: %d\n", socketClient);

	char test[8] = "message";

	send(socketClient, (const char *)&test, sizeof(test), 0);

	close(socketClient);
	close(socketServer);
	printf("close\n");


	printf("test\n");
	return 0;
}


etape 1:
connections des joueurs :
6 maxs: un thread chacun -> dialogue pour les requetes



etape 2: generer le terrain

etape 3: chacun son tour x3

etape 4: fermer les dialogues


*/