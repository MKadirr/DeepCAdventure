#include "../../include/host.h"

void* CLientService(int socket, struct Player* Players)
{


    struct Flag_sock flag;
    int isListening = 1;
    while(isListening)
    {
        recv(socket, (struct Flag_sock*)&flag, sizeof(struct Flag_sock), 0);
    }
    
}