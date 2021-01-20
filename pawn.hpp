#pragma once 
#include "libs.hpp"

class Pawn
{
    sf::CircleShape* bodyPointer;
    Coordinates pawnCoordinates;
    public:
    Pawn (sf::CircleShape* initialBodyPointer, Coordinates initialPawnCoordinates): bodyPointer(initialBodyPointer), pawnCoordinates(initialPawnCoordinates) {}
    
};