#include "libs.hpp"
#include "pawn.hpp"
#include "player.hpp"

class Logic
{
    int** simplifiedLogicArray;
    Pawn*** logicArray;
    public:
    Logic(Player* whitePlayer, Player* blackPlayer, int ** initialBoardPostion);
};
