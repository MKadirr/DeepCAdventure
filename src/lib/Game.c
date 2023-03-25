#include "../../include/dca_lib.h"


void InitBaseGame(struct GameStatement* gt)
{
    gt->MaxOxigene = MAX_OXYGEN;
    gt->nbTurn = NB_TURN;
    gt->Board = genBoard();
}

void Start(struct GameStatement* gt)
{
    int nbPlayer = gt->nbPlayer;
    struct Case* Board = gt->Board;

    int oxygene;
    int curPlayer = 0;
    for (int turn = 0; turn < gt->nbTurn; i++)
    {
        oxygene = gt->MaxOxigene;
        for(int i = 0; i < nbPlayer; i++) gt->Players[i]->pos = gt->Board;
        int choice;

        while(oxygene > 0)
        {
            oxygene -= getNbTreasure(gt->Players[i]);
            
            choice = gt->Players[i].Move(gt, gt->Players[i], gt->Players[i]->argument);

            for(int k = 0; k < 10)
            if(gt->Players[i].ascending && choice)
        }
    }
    
}