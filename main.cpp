#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1440, 1080), "Bug World");
    Game game = Game(&window);
    Game::setGame(&game);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            game.update(event);
        }
        window.clear();
        game.drawAll();
        window.display();
    }

    return 0;
}
