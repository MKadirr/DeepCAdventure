
#include "dca_lib.h"



int getNbTreasure(int stock[])
{
    if(len(stock) < 4) return 0;

    return stock[0] + stock[1] + stock[2] + stock[3];
}

void printStock(int stock[])
{
    printf("[%d,%d,%d,%d]",stock[0],stock[1],stock[2],stock[3]);
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
            tmp->previous = act;

            if(i == 0 && j == 0) head = tmp;
            act->next = tmp;
        }
    }

    return head;
}

void printCase(struct Case* c)
{
    if(c == NULL) return;
    
    printf("%d) ");

    int tmp = getNbTreasure(c->stack);
    if(tmp == 0)
        printf("empty\n");
    else if (tmp == 1)
    {
        if(c->stack[0]) tmp = 1;
        if(c->stack[1]) tmp = 2;
        if(c->stack[2]) tmp = 3;
        if(c->stack[3]) tmp = 4;

        printf("treasur T%d\n", tmp);
    }
    else
    {
        printStock(c->stack);
        printf("\n");
    }

    if(c->player == NULL)
    {
        printf("Player : ");
        printPlayer(c->player);
    }
}

void printBoard(struct Case* c)
{
    if(c == NULL) return;

    if(c->deep == 0)
    printf("Submarine\n");
    printCase(c->next);
}

void numerote(struct Case* c, int deep)
{
    if(c != NULL)
    {
        c->deep = deep;
        numerote(c->next, deep + 1);
    }
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