#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Button.h"
#include "AddBug.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1440, 1080), "Bug World");
    Game* game = Game::getGame();
    Button* button;
    game->setWindow(&window);
    game->createTiles();
    game->spawnButtons();

    while (window.isOpen())
    {                                                        
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::A) {
                    game->spawnAnt();
                }
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                if (event.key.code == sf::Keyboard::Up) {
                    game->increaseBGMVolume();
                    game->increaseSFXVolume();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    game->decreaseBGMVolume();
                    game->decreaseSFXVolume();
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button->ifClick((float)event.mouseButton.x, (float)event.mouseButton.y)){
                        
                    }
                }
            }
        }
        game->update(event);
        window.clear(sf::Color::White);
        game->drawAll();
        window.display();
    }

    return 0;
}
