#include <stdlib.h>
#include <winsock2.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include "../src/lib/dca_lib.h"

#ifndef _HOST_
    #define _HOST_

    #define ABS(value) (value < 0 ? -value : value)
    #define TRUE 1
    #define FALSE 0;
#endif