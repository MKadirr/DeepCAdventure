#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dca_lib.h"
#include "win_lib.h"

#ifndef _HOST_
    #define _HOST_

    #define ABS(value) (value < 0 ? -value : value)
    #define TRUE 1
    #define FALSE 0;
#endif