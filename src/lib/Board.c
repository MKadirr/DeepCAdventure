
#include "../../include/dca_lib.h"



int getNbTreasure(char stock[])
{
    return stock[0] + stock[1] + stock[2] + stock[3];
}

void printStock(char stock[])
{
    printf("[%d,%d,%d,%d]",stock[0],stock[1],stock[2],stock[3]);
}

struct Case* genBoard()
{
    struct Case* head = (struct Case*)malloc(sizeof(struct Case*));
    for(int k =0; k < 4; k++) head->stack[k] = 0;
    struct Case* act = head;
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

            act->next = tmp;
        }
    }

    numerote(head, 0);

    return head;
}

void printCase(struct Case* c)
{
    if(c == NULL) return;
    
    printf("%d) ",c->deep);

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