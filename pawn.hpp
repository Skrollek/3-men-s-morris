#pragma once 
#include "libs.hpp"


class Pawn
{
    sf::CircleShape body;
    Coordinates pawnCoordinates;
    public:
    Pawn (bool color, Coordinates initialPawnCoordinates);
    void draw(sf::RenderWindow* targetWindow);
    
};