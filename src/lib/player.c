#include "dca_lib.h"

void printPalyer(struct Player* p)
{
    if(p == NULL) return;
    printf("%s(score : %d)\n",p->name, p->total_point);
    printf("%s :",(p->ascending?"en monté":"en descente"));

    for(int i = 0 ; i < 7; i++)
    {
        if(getNbTreasure(p->inv[i]))
        {
            printf(" [%d,%d,%d,%d]",p->inv[i][0],p->inv[i][1],p->inv[i][2],p->inv[i][3]);
        }
    }
    printf("\n");
}

/// @brief move player 
/// @param p palyer concerned
/// @param n positive to go deeper, negative otherwise
/// @return 
int move(struct Player* p, int n)
{
    struct Case* tmp = p->pos;

    if(n > 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(tmp->next == NULL) i = n;
            else 
            {
                if(tmp->previous) i--;
                tmp = tmp->next;
            }
            if(tmp->player != NULL)
            {
                p->pos->player = NULL;
                while(tmp->player != NULL)
                    tmp = tmp->previous;
            }
            
        }
    }
    else
    {
        n = -n;
        for(int i = 0; i < n; i++)
        {
            if(tmp->previous == NULL) i = n;
            else 
            {
                if(tmp->previous) i--;
                tmp = tmp->next;
            }
        }
    }

    p->pos->player = NULL;
    p->pos = tmp;
    p->pos->player = p;
}