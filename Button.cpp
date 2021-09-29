#include "Button.h"
#include "Game.h"
#include "Entity.h"

void Button::onClick() {
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left) {
				if (buttonRect.contains(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y))) {
					click = 1;
				}
				else {
					click = 0;
				}
			}
		}
	}
}