
#include "dca_lib.h"


int getNbTreasure(int stock[])
{
    if(len(stock) < 4) return -1;

    return stock[0] + stock[1] + stock[2] + stock[3];
}

struct Case* genBoard()
{
    struct Case* head = NULL;
    struct Case* act = NULL;
    struct Case* tmp = NULL;
    
    

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            tmp = (struct Case*)malloc(sizeof(struct Case*));
            for(int k =0; k < 4; k++) tmp->stack[k] = 0;

            tmp->stack[i] = 1;
            tmp->next = NULL;

            if(i == 0 && j == 0) head = tmp;
            act->next = tmp;
        }
    }

    return head;
}

void clean(struct Case* c)
{
    if(c != NULL && c->next != NULL)
    {
        if(getNbTreasure(c->next->stack) == 0)
        {
            struct Case* tmp = c->next;
            c->next = tmp->next;
            free(tmp);
        }
        clean(c->next);
    }
}

void destroyBoard(struct Case* c)
{
    if(c != NULL)
    destroyBoard(c->next);
    free(c);
}