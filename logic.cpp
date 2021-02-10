#include "pawn.hpp"
#include "player.hpp"
#include "libs.hpp"
#include "logic.hpp"

Logic :: Logic(Player* whitePlayer, Player* blackPlayer, int ** initialBoardPostion)
{
    if(initialBoardPostion == NULL)
    {
        simplifiedLogicArray = new int*[3];
        for(int i = 0; i < 3; ++i)
        {
            simplifiedLogicArray[i] = new int[3] {-1,-1,-1};
        }
        logicArray = new Pawn**[3];
        for(int i = 0; i < 3; ++i)
        {
            logicArray[i] = new Pawn*[3];
        }
        for(int x = 0; x < 3; ++x)
        {
            for(int y = 0; y < 3; ++y)
            {
                logicArray[x][y] = (Pawn*)((uint64_t)whitePlayer->getPawnByCoordinates(Coordinates(x,y)) + (uint64_t)blackPlayer->getPawnByCoordinates(Coordinates(x,y)));
                if(logicArray[x][y] != NULL)
                   simplifiedLogicArray[x][y] = logicArray[x][y]->getColor();
            }
        }
    }
    else /// to be implemented
    {

    }
}