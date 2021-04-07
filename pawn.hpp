#pragma once 
#include "libs.hpp"


class Pawn
{
    sf::CircleShape body; // sfml class used to draw representation of pawn
    Coordinates pawnCoordinates; // pawn coordinates that describe its position on board 
    public:
    Pawn (bool color, Coordinates initialPawnCoordinates); // constructor sets color and initial position of body. 1 - white, 0 - black
    void draw(sf::RenderWindow* targetWindow); // draws pawn in window 
    void setCoordinates(Coordinates newCoordinates); // sets new coordinates and body position
    Coordinates getCoordinates(); // returns current coordinates
    bool getColor();
    const sf::Color getSFColor();
    void setOutlineColor(sf::Color newColor);
    void setBodyColor(sf::Color newColor);
};