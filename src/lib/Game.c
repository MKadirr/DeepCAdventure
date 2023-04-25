#include "../../include/dca_lib.h"


/// @brief Initiate the GameStatement with base states and generate board
/// @param gt 
void InitBaseGame(struct GameStatement* gt)
{
    gt->MaxOxigene = MAX_OXYGEN;
    gt->nbTurn = NB_TURN;
    gt->Board = genBoard();
}

/// @brief throw 2des from 1-3
/// @param nbTresor
/// @return 
int 
LanceLesDes(int nbTresor)
{
    int tmp = random()%3 + random()%3 + 2 - nbTresor;
    return tmp>0?tmp:0;
}


/// @brief play the game
/// @param gt a game statement (cf: GameStatement)
void Start(struct GameStatement* gt)
{
    srand(time(NULL));
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
        char choice;

        while(oxygene > 0)
        {
            oxygene -= getNbTreasure(gt->Players[i]);

            choice = gt->Players[curPlayer].Move(gt, gt->Players[curPlayer], gt->Players[curPlayer]->argument);
            if(choice > 0 && gt->Players[curPlayer].ascending) choice = 0;

            move(gt->Players[curPlayer], (choice > 0?1:-1) * LanceLesDes(getNbTreasure(gt->Players[i])));

            choice = gt->Players[curPlayer].Action(gt, gt->Players[curPlayer], gt->Players[curPlayer]->argument);
            if(choice)
            {
                if(choice&PICK_UP && getNbTreasure(gt->Players[curPlayer].pos->stack))
                {
                    Take(gt->Players[curPlayer].pos->stack, gt->Players[curPlayer])
                }
                else
                {
                    Drop(Take(gt->Players[curPlayer].pos->stack, gt->Players[curPlayer]), choice)
                }
            }

            curPlayer++;
        }
    }
    
}