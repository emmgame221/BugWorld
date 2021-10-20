#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Button.h"
#include "InfoMenu.h"

  int Menu::bugMenu() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Info Menu");
    infoText.setString(infoString);
    loadInfo();

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

  std::string Menu::loadInfo() {
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
      infoText.setPosition(sf::Vector2f(100.f, 100.f));
      std::cout << infoString << std::endl;

      return infoString;
  }