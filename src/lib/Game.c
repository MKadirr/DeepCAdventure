#include "../../include/dca_lib.h"


/// @brief Initiate a base game
/// @param gt 
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
        for(int i = 0; i < nbPlayer; i++) 
        {
            gt->Players[i]->pos = gt->Board;
            gt->Players[i].inSubmarine = FALSE;
            gt->Players[i].ascending = FALSE;
        }
        int choice;

        while(oxygene > 0)
        {
            oxygene -= getNbTreasure(gt->Players[i]);

            choice = 0;

            int k = 10;
            while(k && !choice)
            {
                choice = gt->Players[curPlayer].Move(gt, gt->Players[curPlayer], gt->Players[curPlayer]->argument);
                if(choice >= 0 && gt->Players[curPlayer].ascending) choice = 0;
            }
            

            
        }
    }
    
}