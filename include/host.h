#include <stdlib.h>
#include "../src/lib/dca_lib.h"
#include "../src/win_lib/win_lib.h"
#include <winsock2.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>

#ifndef _HOST_
    #define _HOST_

    #define ABS(value) (value < 0 ? -value : value)
    #define TRUE 1
    #define FALSE 0

    

    //player

    typedef struct Player{
        int socket;
        char name[16];
        int inv[7][4];
    };



#endif