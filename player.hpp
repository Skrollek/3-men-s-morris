#pragma once
#include "libs.hpp"
#include "pawn.hpp"

class Player
{
    Pawn* playerPawns;
    char playerType;
    bool playerColor;
    public:
    Player(bool initialPlayerColor); // creates player instance of Player class creates pawns according to input color, also sets pawns coordinates to initial ones. 1 - white, 0 - black
    void draw(sf::RenderWindow* targetWindow); // draws players pawns 
};