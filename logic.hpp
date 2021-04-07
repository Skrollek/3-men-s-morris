#include "libs.hpp"
#include "pawn.hpp"
#include "player.hpp"

class Logic
{
    int** simplifiedLogicArray;
    Pawn*** logicArray;
    public:
    Logic(Player* whitePlayer, Player* blackPlayer, int ** initialBoardPostion);
    Logic(); // creates default board. Not to be used to initialize a board. But it can be used to compare if current state of board is equal to initial state.
    bool onClick(Coordinates mouseClickCoordinates, bool playerColor);
    bool operator == (const Logic &  A);
};
