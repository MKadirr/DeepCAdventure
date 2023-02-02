#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef _DCALIB_
    #define _DCALIB_

    #define ABS(value) (value < 0 ? -value : value)
    #define TRUE 1
    #define FALSE 0

    //game stats
    #define MAX_PLAYER 6
    #define MAX_OXYGEN 25


    //Tag definer
        //server->client (0-127)
        #define TPING 1;
        #define TASK_NAME 2;
        #define TBEGIN 3;
        #define TUTURN 4;
        #define TEND 5;

        //client->server (128-255)
        #define TEXIT 255;

    //Connection
    #define BASE_PORT 33333


    //struct
    typedef struct Case{
        struct Case* next;
        struct Case* previous;
        struct Player* player;

        int deep;
        char stack[4];
    } Case;

    typedef struct Player{
        unsigned int socket;
        char name[16];
        char inv[7][4];

        struct Case* pos;

        int total_point;

        char ascending;
        char inSubmarine;
    } Player;

    //palyer.c
    void printPlayer(struct Player* p);
    int move(struct Player* p, int n);

    //board.c
    int getNbTreasure(char stock[]);
    void printStock(char stock[]);
    struct Case* genBoard();
    void printCase(struct Case* c);
    void printBoard(struct Case* c);
    void numerote(struct Case* c, int deep);
    void clean(struct Case* c);
    void destroyBoard(struct Case* c);

    //handel.c
    struct Flag_sock{
        char tag;
        int advanced_data;
    };


#endif
