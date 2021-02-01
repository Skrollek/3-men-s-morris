#include "libs.hpp"
#include "pawn.hpp"

void resizeView(const sf::RenderWindow *window, sf::View* view)
{
    float aspectRatio = float(window->getSize().x) / float(window->getSize().y);
    view->setSize(VIEW_SIZE*aspectRatio, VIEW_SIZE);
}

int main()
{

    sf::RenderWindow mainWindow (sf::VideoMode(800,800), "3 men's morris");
    sf::View mainView(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_SIZE, VIEW_SIZE));
    mainWindow.setFramerateLimit(60u);
    sf::Vertex lines[][2] = {{sf::Vertex(sf::Vector2f(-450,450)),  sf::Vertex(sf::Vector2f(450,-450)) }, // first diagonal
                             {sf::Vertex(sf::Vector2f(-450,-450)), sf::Vertex(sf::Vector2f(450,450)) },  // second diagonal
                             {sf::Vertex(sf::Vector2f(450,450)),  sf::Vertex(sf::Vector2f(450,-450)) },  // right vertical line
                             {sf::Vertex(sf::Vector2f(-450,-450)),  sf::Vertex(sf::Vector2f(450,-450)) },  // upper horizontal line
                             {sf::Vertex(sf::Vector2f(-450,450)), sf::Vertex(sf::Vector2f(-450,-450)) }, // left vertical line
                             {sf::Vertex(sf::Vector2f(-450,450)), sf::Vertex(sf::Vector2f(450,450)) }, // bottom horizontal line
                             {sf::Vertex(sf::Vector2f(0,-450)), sf::Vertex(sf::Vector2f(0,450)) }, // middle vertical line
                             {sf::Vertex(sf::Vector2f(-450,0)), sf::Vertex(sf::Vector2f(450,0)) }  // middle horizontal line
                            };
    Pawn pawnOne(true, sf::Vector2i(0,0));
    Pawn pawnTwo(false, sf::Vector2i(2,2));
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
        pawnOne.draw(&mainWindow);
        pawnTwo.draw(&mainWindow);
        mainWindow.display();
        
    }


    return 0;
}