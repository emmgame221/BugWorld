#include <SFML/Graphics.hpp>
#include "Button.h"
#include "InfoMenu.h"

  int Menu::bugMenu() {
    sf::RenderWindow window(sf::VideoMode(1400, 500), "Info Menu");
    
    infoText.setString(infoString);
    window.draw(infoText);

    font = sf::Font();
    font.loadFromFile("./resources/NewYork.otf");
    inputFile.open("./resources/BugInfo.txt");

    while (!(inputFile.eof())) {
        ch = inputFile.get();
        infoString += ch;
    }

    infoText.setFont(font);
    infoText.setString(infoString);
    infoText.setFillColor(sf::Color::Black);
    infoText.setPosition(sf::Vector2f(5.f, 0.f));
    window.draw(infoText);
    //std::cout << infoString << std::endl;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        window.clear(sf::Color::White);
        infoText.setString(infoString);
        window.draw(infoText);
        window.display();
    }
    return 0;
}