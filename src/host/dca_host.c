#include "../../include/host.h"

#include <string.h>

//#include ""



int genPlayer(struct Player* Players, char *name, int socket)
{
    int i = 0;
    while(i < MAX_PLAYER && Players[i].name != '\0') i++;

    if(i == MAX_PLAYER) return -1;

    strcpy(Players[i].name, name);
    Players[i].socket = socket;
    for(int k = 0; i < 7; i++)
        for(int j = 0; j < 4; j++)
            Players[i].inv[k][j] = 0;

}

int main(int argc, char** argv)
{
    struct Player Players[MAX_PLAYER];
    for(int i = 0; i < MAX_PLAYER; i++)
        Players->socket = -1;

    
}

/*

etape 1:
connections des joueurs :
6 maxs: un thread chacun -> dialogue pour les requetes



etape 2: generer le terrain

etape 3: chacun son tour x3

etape 4: fermer les dialogues


*/