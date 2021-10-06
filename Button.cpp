#include "Button.h"
#include "Game.h"
#include "Entity.h"

Button::Button(sf::Sprite s) {
	sprite = s;
	buttonRect = sprite.getGlobalBounds();
}

int Button::ifClick(float x, float y) {
	if (buttonRect.contains(sf::Vector2f(x, y)) {
		return 1;
	}
	else {
		return 0;
	}
}