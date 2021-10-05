#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Button.h"
#include "AddBug.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1440, 1080), "Bug World");
    Game* game = Game::getGame();
    game->setWindow(&window);
    game->createTiles();
    Button* addAnt;
    Button* subtractAnt;
    Button* addLadybug;
    Button* subtractLadybug;
    AddBug* antButton;
    AddBug* ladybugButton;

    while (window.isOpen())
    {
        game->moveBugs();                                                         //currently makes bugs move off screen
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::A) {
                    game->spawnAnt();
                }
            }
            game->update(event);
        }
        window.clear(sf::Color::White);
        game->drawAll();
        window.display();
    }

    return 0;
}
