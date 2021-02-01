#include "pawn.hpp"

extern const float VIEW_SIZE;
extern const float VIEW_STEP;

Pawn :: Pawn (bool color, Coordinates initialPawnCoordinates): pawnCoordinates(initialPawnCoordinates) 
    {
        body.setRadius(VIEW_SIZE * 0.05f);
        body.setOrigin(body.getRadius(), body.getRadius());
        if (color)  // white
        {
            body.setFillColor(sf::Color::White);
        }
        else        // black
        {
            body.setFillColor(sf::Color::Black);
            body.setOutlineColor(sf::Color::White);
            body.setOutlineThickness(0.1 * body.getRadius());
            body.setRadius(body.getRadius()- body.getOutlineThickness());
        }
        body.setPosition((VIEW_STEP) * (initialPawnCoordinates.x - 1), (VIEW_STEP) * (initialPawnCoordinates.y - 1));
    }

void Pawn::draw(sf::RenderWindow* targetWindow)
{
    targetWindow->draw(this->body);
}