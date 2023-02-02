#include "../../include/host.h"


int main(int argc, char** argv)
{
    if(argc < 2)
    {
		printf("No ip given, aborted...");
        exit(EXIT_FAILURE);
	}


	printf("%s]\n", argv[1]);

    struct Player Players[MAX_PLAYER];

    for(int i = 0; i < MAX_PLAYER; i++)
    {
        Players->socket = INVALID_SOCKET;
    }
	
	WSADATA cotest;
	WSAStartup(MAKEWORD(2,2), (LPWSADATA)&cotest);

    int socketServer = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addrServer;
	addrServer.sin_addr.s_addr = inet_addr(argv[1]);
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(BASE_PORT);

    bind(socketServer, (const struct sockaddr *)&addrServer, sizeof(addrServer));
	printf("bind : %d\n", socketServer);

	printf("error : %d\n", WSAGetLastError());

    listen(socketServer, MAX_PLAYER);
	printf("listen\n");

	getchar();

	
	struct sockaddr_in addrClient;
	int csize = sizeof(addrClient);
	Players[0].socket = accept(socketServer, (struct sockaddr *)&addrClient, &csize);
	printf("accept\n");

	printf("client: %d. Welcome\n", Players[0].socket);

	char buffer[64];
	size_t size_buffer = sizeof(buffer);
	/*for(int i = 1; i < 6; i++)
	{
		getline((char **)&buffer, (size_t *)&size_buffer, stdin);
		if(strcmp(buffer, ""))
		Players[1].socket = accept(socketServer, (struct sockaddr *)&addrClient, &csize);
		printf("New player: %d\n", Players[1].socket);
	}




	for(int i = 0; i < 6; i++)
	{
		if(Players[i].socket != INVALID_SOCKET) 
		{
			closesocket(Players[i].socket);
			printf("client %d closed\n", i);
		}
	}*/

	char test[16];
	

	recv(Players[0].socket, (char *)&test, 16, 0);

	printf(test); putchar('\n');

	closesocket(Players[0].socket);
    closesocket(socketServer);
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