#include "../../include/host.h"

void CLientService(int socket)
{
    struct Flag_handel flag;
    int isListening = 1;
    while(isListening)
    {
        recv(socket, (struct Flag_handel*)&flag, sizeof(struct Flag_handel), 0);
    }
    
}