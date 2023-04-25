#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Time.h>

#ifndef _DCALIB_
    #define _DCALIB_

    #define ABS(value) (value < 0 ? -value : value)
    #define TRUE 1
    #define FALSE 0

    //game stats
    #define MAX_PLAYER 6
    #define MAX_OXYGEN 25
    #define NB_TURN 3

    // min/max treasur value
    #define SMALL_MIN 0
    #define SMALL_MAX 4
    #define MEDIUM_MIN 5

    //Name
    #define SLOT_0  0b00000001
    #define SLOT_1  0b00000010
    #define SLOT_2  0b00000100
    #define SLOT_4  0b00001000
    #define SLOT_5  0b00010000
    #define SLOT_6  0b00100000
    #define SLOT_7  0b01000000
    #define PICK_UP 0b10000000
    #define DO_NOTHING 0


    //struct
    typedef struct Case{
        struct Case* next;
        struct Case* previous;
        struct Player* player;

        int deep;
        char stack[4];
    } Case;

    typedef struct Player{
        // move select between >0 => go deeper, else go upper
        char (*Move) (struct GameStatement, struct Player, void*);

        /*
            return a action between take (0b1xxxxxxx/PIKC_UP), drop (0b0gfedcba, with a to drop case 1, b case b, etc), nothing (0/DO_NOTHING)
        */
        char (*Action) (struct GameStatement, struct Player, void*);
        void* argument;
        char name[16];
        char inv[7][4];

        struct Case* pos;

        int total_point;

        char ascending;
        char inSubmarine;
    } Player;

    typedef struct GameStatement{
        int nbPlayer;
        struct Player* Players;

        struct Case* Board;

        int nbTurn;
        int MaxOxigene;
    } GameStatement;

    //player.c

    void Take(char* treasure, struct Player* player);
    void Drop(char* treasure, struct Player* player, char choice)
    void printPlayer(struct Player* p);
    int move(struct Player* p, int n);
    void getNbStack(struct Player* p);

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
