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
Logic :: Logic()
{
    simplifiedLogicArray = new int*[3];
    for(int i = 0; i < 3; ++i)
    {
        simplifiedLogicArray[i] = new int[3] {1,-1,0};
    }
}
bool Logic :: operator == (const Logic &  A)
{
    for(int i =0; i < 0; ++i)
    {
        for(int j = 0; j < 0; ++j)
        {
            if(A.simplifiedLogicArray[i][j] != this->simplifiedLogicArray[i][j])
                return false;
        }
    }
    return true;
}

bool Logic :: onClick(Coordinates mouseClickCoordinates, bool playerColor)
{
    static Pawn* currentlySelectedPawn = NULL;
    int i = (mouseClickCoordinates.x + VIEW_SIZE/2)/VIEW_STEP - 1, j = (mouseClickCoordinates.y + VIEW_SIZE/2)/VIEW_STEP - 1;
    std::cout << i << " " << j << std::endl;
    if(simplifiedLogicArray[i][j] != -1)
    {
        currentlySelectedPawn = logicArray[i][j];
    }
    else if (currentlySelectedPawn != NULL)
    {
        if(i == currentlySelectedPawn->getCoordinates().x || j == currentlySelectedPawn->getCoordinates().y || i == currentlySelectedPawn->getCoordinates().x -currentlySelectedPawn->getCoordinates().y == i-j)
        {
            std::swap(logicArray[currentlySelectedPawn->getCoordinates().x][currentlySelectedPawn->getCoordinates().y], logicArray[i][j]);
            std::swap(simplifiedLogicArray[currentlySelectedPawn->getCoordinates().x][currentlySelectedPawn->getCoordinates().y], simplifiedLogicArray[i][j]);
            currentlySelectedPawn->setCoordinates(Coordinates(i,j));
            return false;
        }
        
    }
    return true;
    
}