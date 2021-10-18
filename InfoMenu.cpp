#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Button.h"
#include "InfoMenu.h"

  int Menu::bugMenu() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Info Menu");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;

                window.clear(sf::Color::White);
                window.display();
            }
        }
    }
    return 0;
}