#include "Button.h"
#include "Game.h"
#include "Entity.h"

Button::Button(sf::Sprite s, std::function<void()> func) {
	sprite = s;
	toCall = func;
}

void Button::onClick() {
	toCall();
}