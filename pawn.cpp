#include "pawn.hpp"

extern const float VIEW_SIZE;
extern const float VIEW_STEP;

Pawn :: Pawn (bool color, Coordinates initialPawnCoordinates): pawnCoordinates(initialPawnCoordinates) // set pawnCooridinates to initial ones 
    {
        body.setRadius(VIEW_SIZE * 0.05f);
        if (color)  // white
        {
            body.setFillColor(sf::Color::White);
        }
        else        // black
        {
            body.setFillColor(sf::Color::Black);
            body.setOutlineColor(sf::Color::White);
            body.setOutlineThickness(0.1 * body.getRadius());
            body.setRadius(body.getRadius() - body.getOutlineThickness()); // change radius to match white pawn in size
        }
        body.setOrigin(body.getRadius(), body.getRadius()); // set origin of body to center of circle
        body.setPosition(VIEW_STEP * initialPawnCoordinates.x, VIEW_STEP * initialPawnCoordinates.y); // set body position according to pawnCoordinates
    }

void Pawn::draw(sf::RenderWindow* targetWindow)
{
    targetWindow->draw(body);
}

void Pawn::setCoordinates(Coordinates newCoordinates)
{
    pawnCoordinates = newCoordinates;
    body.setPosition(VIEW_STEP * pawnCoordinates.x, VIEW_STEP * pawnCoordinates.y);
}

Coordinates Pawn::getCoordinates()
{
    return pawnCoordinates;
}

bool Pawn::getColor()
{
    if(body.getFillColor() == sf::Color::White)
        return 1;
    return 0;
}