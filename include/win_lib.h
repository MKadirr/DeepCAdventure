#include <winsock2.h>
#include <windows.h>

#ifndef _WIN_LIB_
    #define _WIN_LIB_

    #define ABS(value) (value < 0 ? -value : value)
    #define TRUE 1
    #define FALSE 0
    
#endif