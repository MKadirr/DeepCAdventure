#include <winsock2.h>
//#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/win_lib.h"
#include "../include/dca_lib.h"

int main(int argv, char *argc[])
{
    if(argv < 2)
	{
        printf("No ip given, aborted...");
        exit(EXIT_FAILURE);
	}

    
    int socketClient = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addrCLient;
    addrCLient.sin_addr.s_addr = inet_addr(argc[1]);
	addrCLient.sin_family = AF_INET;
	addrCLient.sin_port = htons(BASE_PORT);

    connect(socketClient, (const struct sockaddr*)&addrCLient, sizeof(addrCLient));
    printf("connecté\n");

    closesocket(socketClient);
    return 0;
    

}
/*
	int socketClient = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in addrCLient;
	addrCLient.sin_addr.s_addr = inet_addr("127.0.0.1");
	addrCLient.sin_family = AF_INET;
	addrCLient.sin_port = htons(30000);

	connect(socketClient, (const struct sockaddr*)&addrCLient, sizeof(addrCLient));
	printf("connecté\n");

	char test[8];
	recv(socketClient, (char *)&test, sizeof(test), 0);
	printf("%s %d\n", test);

	close(socketClient);
    */