#include "Bug.h"
#include "Game.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <random>


void Bug::move() {
	sf::Vector2f move;
	sprite.move(move);
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
	sprite.setOrigin(sf::Vector2f(game->getTileSize()/2,0));
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

Pheremone::Pheremone(sf::Vector2f inPt, int inType) {
	this->point = inPt;
	this->type = inType;
}
