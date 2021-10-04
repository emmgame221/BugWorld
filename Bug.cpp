#include "Bug.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

void Bug::move() {
	sprite.move(sf::Vector2f(1.0f,1.0f));
}

void Bug::eat() {
}

Ant::Ant() {
	this->speed = 1.0f;
	this->eatSpeed = 1.0f;
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->antTexture);
	sprite.setPosition(sf::Vector2f(0.0f,0.0f));
	float scale = game->getTileSize() / sprite.getLocalBounds().width;
	sprite.setScale(sf::Vector2f(scale,scale));
}

Ladybug::Ladybug() {
	this->speed = 1.0f;
	this->eatSpeed = 1.0f;
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->ladybugTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	float scale = game->getTileSize() / sprite.getLocalBounds().width;
	sprite.setScale(sf::Vector2f(scale, scale));
}
