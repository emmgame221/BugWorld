#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Button.h"

const int WIN_MIN_WIDTH = 720;
const int WIN_MIN_HEIGHT = 540;
const int WIN_DEF_WIDTH = 1440;
const int WIN_DEF_HEIGHT = 1080;
const int START_GRID_WIDTH = 15;
const int START_GRID_HEIGHT = 10;

int main()
{
    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    if (mode.width >= WIN_DEF_WIDTH) {
        mode.width = WIN_DEF_WIDTH;
    }
    if (mode.height >= WIN_DEF_HEIGHT) {
        mode.height = WIN_DEF_HEIGHT;
    }
    sf::RenderWindow window(mode, "Bug World");
    Game* game = Game::getGame();
    game->setWindow(&window);
    game->setGridSize(START_GRID_WIDTH, START_GRID_HEIGHT);
    game->initLevel();
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
                    game->checkClick(event.mouseButton.x, event.mouseButton.y);
                }
                break;
            case sf::Event::Resized:
                if (event.size.width < WIN_MIN_WIDTH && event.size.height < WIN_MIN_HEIGHT) {
                    window.setSize(sf::Vector2u(WIN_MIN_WIDTH, WIN_MIN_HEIGHT));
                }
                else if (event.size.width < WIN_MIN_WIDTH) {
                    window.setSize(sf::Vector2u(WIN_MIN_WIDTH, event.size.height));
                }
                else if (event.size.height < WIN_MIN_HEIGHT) {
                    window.setSize(sf::Vector2u(event.size.width, WIN_MIN_HEIGHT));
                }
                else {
                    game->resize();
                }
                break;
            }
        }
        game->update();
        window.clear(sf::Color::White);
        game->drawAll();
        window.display();
    }

    return 0;
}
