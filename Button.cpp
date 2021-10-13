#include "Button.h"
#include "Game.h"
#include "Entity.h"

Button::Button(sf::Sprite s, std::function<void()> func) {
	sprite = s;
	toCall = func;
}

Button::Button(sf::Text t) {
	sf::Text  text;
	text = t;
}

void Button::onClick() {
	toCall();
}