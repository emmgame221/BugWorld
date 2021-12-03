#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Button.h"
#include "InfoMenu.h"

const int WIN_MIN_WIDTH = 720;
const int WIN_MIN_HEIGHT = 540;
const int WIN_DEF_WIDTH = 1440;
const int WIN_DEF_HEIGHT = 1080;

int main()
{
    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    mode.height -= 30;
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
    game->spawnLabels();
    Menu menu;

    sf::Text title;

    sf::Font font;
    font.loadFromFile("./resources/NewYork.otf");
    title.setFont(font);
    title.setCharacterSize(80);
    title.setString("Bug World");
    title.setOrigin(sf::Vector2(title.getLocalBounds().width / 2, title.getLocalBounds().height / 2));
    title.setPosition(window.getSize().x * .5 , 100);

    std::vector<sf::Sprite> buttons;
    sf::Sprite newGame;
    sf::Sprite load;
    sf::Sprite options;
    sf::Sprite exit;

    std::vector<std::string> butFiles = { "button_new-game.png", "button_load.png", "button_options.png", "button_exit.png"};


    std::vector<sf::Texture> butText;

    for (int i = 0; i <= 3; i++) {
        butText.push_back(sf::Texture());
        butText[i].loadFromFile("./resources/" + butFiles[i]);
        buttons.push_back(sf::Sprite(butText[i]));
    }

    
    while (window.isOpen())
    {                                                        
        sf::Event event;

        while (game->menuFlag) {
            while (window.pollEvent(event)) {
                switch (event.type) {
                case sf::Event::KeyPressed:
                    
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        for (int i = 0; i <= 3; i++) {
                            if (buttons[i].getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y)) {
                                switch (i)
                                {
                                case 0:
                                    game->menuFlag = false;
                                    break;
                                case 1:
                                    game->load();
                                    game->menuFlag = false;
                                    break;
                                case 2:
                                    break;
                                case 3:
                                    window.close();
                                    return 0;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            window.clear(sf::Color(22, 56, 0));
            window.draw(title);

            for (int i = 0; i <= 3; i++) {
                buttons[i].setOrigin(sf::Vector2f(buttons[i].getLocalBounds().width/2, buttons[i].getLocalBounds().height/2));
                buttons[i].setPosition(window.getSize().x / 2, (100 * i) + 250);
                buttons[i].setTexture(butText[i]);
                window.draw(buttons[i]);
            }
            window.display();
        }

        while (window.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                game->save();
                
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
                if (event.key.code == sf::Keyboard::Space) {
                    menu.bugMenu();
                }
                if (event.key.code == sf::Keyboard::N) {
                    game->nextLevel();
                }
                if (event.key.code == sf::Keyboard::P) {
                    game->prestige();
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    game->checkClick(event.mouseButton.x, event.mouseButton.y);
                }
                break;
            case sf::Event::Resized:
                float aspectRatio = (float)event.size.width / (float)event.size.height;

                if (event.size.width < WIN_MIN_WIDTH && event.size.height < WIN_MIN_HEIGHT) {
                    window.setSize(sf::Vector2u(WIN_MIN_WIDTH, WIN_MIN_HEIGHT));
                }
                else if (event.size.width < WIN_MIN_WIDTH) {
                    window.setSize(sf::Vector2u(WIN_MIN_WIDTH, event.size.height));
                }
                else if (event.size.height < WIN_MIN_HEIGHT) {
                    window.setSize(sf::Vector2u(event.size.width, WIN_MIN_HEIGHT));
                }
                else if (aspectRatio < 1.33f) {
                    int newWidth = event.size.height * 4 / 3;
                    window.setSize(sf::Vector2u(newWidth, event.size.height));
                }
                else if (aspectRatio > 1.79f) {
                    int newHeight = event.size.width * 9 / 16;
                    window.setSize(sf::Vector2u(event.size.width, newHeight));
                }
                else {
                    window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
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
