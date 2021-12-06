#include <SFML/Graphics.hpp>
#include "Button.h"
#include "InfoMenu.h"

  int Menu::bugMenu() {
    sf::RenderWindow window(sf::VideoMode(1000, 700), "Info Menu");
    
    infoText.setString(infoString);
    window.draw(infoText);

    font = sf::Font();
    font.loadFromFile("./resources/NewYork.otf");
    inputFile.open("./resources/BugInfo.txt");

    while (!(inputFile.eof())) {
        ch = inputFile.get();
        infoString += ch;
        stringLen += 1;
    }

    stringLen -= 1;
    infoText.setFont(font);
    infoText.setString(infoString.substr(0, stringLen));
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
        infoText.setString(infoString.substr(0, stringLen));
        window.draw(infoText);
        window.display();
    }
    return 0;
}