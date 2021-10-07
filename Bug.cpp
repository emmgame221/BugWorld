#include "Bug.h"
#include "Game.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <random>


sf::Vector2f movement = sf::Vector2f(1.0f, 1.0f);

void Bug::move() {
	Game* game = Game::getGame();
	std::uniform_real_distribution<> range(0,1);
	int x = sprite.getPosition().x;
	int y = sprite.getPosition().y;

	//sf::Vector2f move = sf::Vector2f(range(game->rng), range(game->rng));
	

	if ((x > (game->getTileW() * game->getTileSize())) || (x < 0)) {
		movement.x *= -1;
	}
	if ((y > (game->getTileH() * game->getTileSize())) || (y < 0)) {
		movement.y *= -1;
	}

	sprite.setRotation(angle(sprite.getPosition() + movement, sprite.getPosition()) - 90);
	sprite.move(normalize(movement));
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
