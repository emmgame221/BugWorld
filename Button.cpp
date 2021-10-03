#include "Button.h"
#include "Game.h"
#include "Entity.h"

int Button::onClick() {
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left) {
				if (buttonRect.contains(sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y))) {
					click = 1;
					return click;
				}
				else {
					click = 0;
					return click;
				}
			}
		}
	}
}