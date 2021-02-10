#include "player.hpp"
#include "pawn.hpp"

Player :: Player(bool initialPlayerColor)
{
    if(initialPlayerColor)
        playerPawns = new Pawn[3] // set color and coordinates of pawns
        { 
          Pawn(initialPlayerColor, Coordinates(0,0)), 
          Pawn(initialPlayerColor, Coordinates(0,1)), 
          Pawn(initialPlayerColor, Coordinates(0,2))
        }; 
    else
        playerPawns = new Pawn[3]
        { 
          Pawn(initialPlayerColor, Coordinates(2,0)), 
          Pawn(initialPlayerColor, Coordinates(2,1)), 
          Pawn(initialPlayerColor, Coordinates(2,2))
        };
    playerColor = initialPlayerColor;
}

void Player::draw(sf::RenderWindow* targetWindow)
{
    for(int i = 0; i < 3; ++i) 
    {
        playerPawns[i].draw(targetWindow);
    }
}

Pawn* Player::getPawnByNumber(unsigned int index)
{
    if (index < 3)
        return (playerPawns + index);
    else return NULL;
}

Pawn* Player::getPawnByCoordinates(Coordinates targetPawnCoordiantes)
{
    for(int i = 0; i < 3; ++i)
    {
        if(playerPawns[i].getCoordinates() == targetPawnCoordiantes)
        return (playerPawns + i);
    }
    return NULL;
}

bool Player::getPlayerColor()
{
    return playerColor;
}