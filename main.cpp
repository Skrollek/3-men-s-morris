#include "libs.hpp"
#include "pawn.hpp"

int main()
{

    sf::RenderWindow mainWindow (sf::VideoMode(600,600), "3 men's morris");
    mainWindow.setFramerateLimit(60u);
    sf::Vertex lines[][2] = {{sf::Vertex(sf::Vector2f(50,50)),  sf::Vertex(sf::Vector2f(550,550)) }, // first diagonal
                             {sf::Vertex(sf::Vector2f(50,550)), sf::Vertex(sf::Vector2f(550,50)) },  // second diagonal
                             {sf::Vertex(sf::Vector2f(50,50)),  sf::Vertex(sf::Vector2f(50,550)) },  // right vertical line
                             {sf::Vertex(sf::Vector2f(50,50)),  sf::Vertex(sf::Vector2f(550,50)) },  // upper horizontal line
                             {sf::Vertex(sf::Vector2f(550,50)), sf::Vertex(sf::Vector2f(550,550)) }, // left vertical line
                             {sf::Vertex(sf::Vector2f(50,550)), sf::Vertex(sf::Vector2f(550,550)) }, // bottom horizontal line
                             {sf::Vertex(sf::Vector2f(300,50)), sf::Vertex(sf::Vector2f(300,550)) }, // middle vertical line
                             {sf::Vertex(sf::Vector2f(50,300)), sf::Vertex(sf::Vector2f(550,300)) }  // middle horizontal line
                            };
    Pawn pawnOne(true, sf::Vector2u(50,50));
    Pawn pawnTwo(false, sf::Vector2u(550,550));
    while(mainWindow.isOpen())
    {
        sf::Event event;
        while(mainWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                mainWindow.close();
        }
        mainWindow.clear(sf::Color::Black);
        for(int i = 0; i < 8; ++i)
        {
            mainWindow.draw(lines[i], 2, sf::Lines);
        }
        pawnOne.draw(&mainWindow);
        pawnTwo.draw(&mainWindow);
        mainWindow.display();
        
    }


    return 0;
}