#include "Button.h"
#include "Game.h"
#include "Entity.h"

int Button::ifClick(float x, float y) {
	if (buttonRect.contains(sf::Vector2f((float)x, (float)y))) {
		return true;
	}
	else {
		return false;
	}
}