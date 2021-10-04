#include "Button.h"
#include "Game.h"
#include "Entity.h"

int Button::onClick(int x, int y) {
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left) {
				if (buttonRect.contains(sf::Vector2f((float)x, (float)y))) {
					return 1;
				}
				else {
					return 0;
				}
			}
		}
	}
}