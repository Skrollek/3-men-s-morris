#include "libs.hpp"
#include "pawn.hpp"
#include "player.hpp"
#include "logic.hpp"
void resizeView(const sf::RenderWindow *window, sf::View* view)
{
    float aspectRatio = float(window->getSize().x) / float(window->getSize().y);
    view->setSize(VIEW_SIZE*aspectRatio, VIEW_SIZE);
}

int main()
{

    sf::RenderWindow mainWindow (sf::VideoMode(800,800), "3 men's morris");
    sf::View mainView(sf::Vector2f(450.0f, 450.0f), sf::Vector2f(VIEW_SIZE, VIEW_SIZE));
    mainWindow.setFramerateLimit(60u);
    sf::Vertex lines[][2] = {
                             {sf::Vertex(sf::Vector2f(0,900)),  sf::Vertex(sf::Vector2f(900,0)) }, // first diagonal
                             {sf::Vertex(sf::Vector2f(0,0)), sf::Vertex(sf::Vector2f(900,900)) },  // second diagonal
                             {sf::Vertex(sf::Vector2f(900,900)),  sf::Vertex(sf::Vector2f(900,0)) },  // right vertical line
                             {sf::Vertex(sf::Vector2f(0,0)),  sf::Vertex(sf::Vector2f(900,0)) },  // upper horizontal line
                             {sf::Vertex(sf::Vector2f(0,900)), sf::Vertex(sf::Vector2f(0,0)) }, // left vertical line
                             {sf::Vertex(sf::Vector2f(0,900)), sf::Vertex(sf::Vector2f(900,900)) }, // bottom horizontal line
                             {sf::Vertex(sf::Vector2f(450,0)), sf::Vertex(sf::Vector2f(450,900)) }, // middle vertical line
                             {sf::Vertex(sf::Vector2f(0,450)), sf::Vertex(sf::Vector2f(900,450)) }  // middle horizontal line
                            };
    Player whitePlayer(1);
    Player blackPlayer(0);
    Logic mainLogic(&whitePlayer, &blackPlayer, NULL);
    bool onMove = 1; // 1 - white 0 - black

    int board[3][3] = {{1,-1,0},{1,-1,0},{1,-1,0}};
    while(mainWindow.isOpen())
    {
        sf::Event event;
        while(mainWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                mainWindow.close();
            else if (event.type == sf::Event::Resized)
                resizeView(&mainWindow, &mainView);

        }
        mainWindow.clear(sf::Color::Black);
        mainWindow.setView(mainView);
        for(int i = 0; i < 8; ++i)
        {
            mainWindow.draw(lines[i], 2, sf::Lines);
        }
        whitePlayer.draw(&mainWindow);
        blackPlayer.draw(&mainWindow);
        mainWindow.display();
        
    }


    return 0;
}