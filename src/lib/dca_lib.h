#include <stdlib.h>

#ifndef _DCALIB_
    #define _DCALIB_

    #define ABS(value) (value < 0 ? -value : value)
    #define TRUE 1
    #define FALSE 0

    
    //game stats
    #define MAX_PLAYER 6
    #define MAX_OXYGEN 25


    //Tag definer
    #define TEXIT 0;
    #define TPING 1;
    #define TASK_NAME 2;
    #define TBEGIN 3;
    #define TUTURN 4;





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
    struct Flag_sock{
        char tag;
        int advanced_data;
    };
    //


#endif
