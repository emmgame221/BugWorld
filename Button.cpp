#include "Button.h"
#include "Game.h"
#include "Entity.h"

Button::Button(sf::Sprite s, std::function<void()> func, float xOffset, float yOffset, float xSize, float ySize) {
	sprite = s;
	toCall = func;
	this->xOffset = xOffset;
	this->yOffset = yOffset;
	this->xSize = xSize;
	this->ySize = ySize;
}

void Button::onClick() {
	toCall();
}

void Button::updateTransform() {
	sf::Vector2u winSize = Game::getGame()->getWindowSize();
	float xpos = winSize.x * xOffset;
	float ypos = winSize.y * yOffset;
	float xscale = winSize.x * xSize / sprite.getLocalBounds().width;
	float yscale = winSize.y * ySize / sprite.getLocalBounds().height;
	sprite.setPosition(sf::Vector2f(xpos, ypos));
	sprite.setScale(sf::Vector2f(xscale, yscale));
}