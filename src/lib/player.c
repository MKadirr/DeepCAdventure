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