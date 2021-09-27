#include "Entity.h"
#include "Button.h"
#include "Game.h"

void Button::onClick() {
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
			if (event.key.code == sf::Keyboard::Space) {
				//Update Level Count
				//New Level
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left) {
				if (buttonRect.contains(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y))) {
					//Call Function for button
				}
			}
		}
	}
}