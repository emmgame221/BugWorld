#include "Bug.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

void Bug::move() {
	sprite.move(sf::Vector2f(1.0f,1.0f));
}

void Bug::eat() {
}

Ant::Ant() {
	Game* game = Game::getGame();
	this->speed = 1.0f;
	this->eatSpeed = 1.0f;
	this->type = 0;
	sprite = sf::Sprite(game->antTexture);
	sprite.setPosition(sf::Vector2f(0.0f,0.0f));
	float scale = game->getTileSize() / sprite.getLocalBounds().width;
	sprite.setScale(sf::Vector2f(scale,scale));
}

Ladybug::Ladybug() {
	Game* game = Game::getGame();
	this->speed = 1.0f;
	this->eatSpeed = 1.0f;
	this->type = 1;
	sprite = sf::Sprite(game->ladybugTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	float scale = game->getTileSize() / sprite.getLocalBounds().width;
	sprite.setScale(sf::Vector2f(scale, scale));
}
