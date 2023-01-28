#include <stdlib.h>

#ifndef _DCALIB_
    #define _DCALIB_

    #define ABS(value) (value < 0 ? -value : value)
    #define TRUE 1
    #define FALSE 0

    typedef struct Case{
        struct Case* next;
        int id_player;
        int stack[4];
    };

    //board.c
    int getNbTreasure(int stock[]);
    struct Case* genBoard();
    void clean(struct Case* c);
    void destroyBoard(struct Case* c);

    //handel.c

    //


#endif
