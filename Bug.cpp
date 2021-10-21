#include "Bug.h"
#include "Game.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>




void Bug::update() {
	Game* game = Game::getGame();
	std::uniform_int_distribution<> range(-5,5);
	int x = sprite.getPosition().x;
	int y = sprite.getPosition().y;

	sf::CircleShape circle = sf::CircleShape(eatRad);
	circle.setOrigin(game->getTileSize(), game->getTileSize());
	circle.setPosition(x,y);
	sf::FloatRect fov = circle.getGlobalBounds();

	

	sf::Vector2f move = sf::Vector2f(range(game->rng), range(game->rng));
	movement += move;
	
	if ((x > (game->getTileW() * game->getTileSize())) || (x < 0)) {
		movement.x *= -1;
	}
	if ((y > (game->getTileH() * game->getTileSize())) || (y < 0)) {
		movement.y *= -1;
	}

	if (game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->lushness == 0) {
		state = 0;
	}

	if (state == 1) {
		if (distance(target, sf::Vector2f(x, y)) >= 10) {
			movement.x = target.x - x;
			movement.y = target.y - y;
		}
		else {
			this->eat(game->getTileAt(target.x / game->getTileSize(),target.y / game->getTileSize()));
			return;
		}
	}
	else {
		for (int xx = 0; xx < game->getTileW(); xx++) {
			for (int yy = 0; yy < game->getTileH(); yy++) {
				sf::Vector2f pt = sf::Vector2f((xx * game->getTileSize()) + (game->getTileSize() / 2), (yy * game->getTileSize()) + (game->getTileSize() / 2));
				if (fov.contains(pt) && game->getTileAt(xx, yy)->lushness >= 1 /* && !game->getTileAt(xx, yy)->eating*/) {
					Tile* tile = game->getTileAt(xx, yy);
					target = pt;
					tile->startEat();
					this->state = 1;
					break;
				}
			}
			if (state == 1)
				break;
		}
	}



	sprite.setRotation(angle(sprite.getPosition() + movement, sprite.getPosition()) - 90);
	sprite.move(normalize(movement) * game->getElapsedTime().asSeconds() * speed);
}

void Bug::eat(Tile* tile) {
	Game* game = Game::getGame();
	eatTimer -= game->getElapsedTime();
	if (tile->lushness >= 1 && eatTimer <= sf::Time::Zero) {
		tile->decLushness();
		game->addFood(1);
		if (tile->lushness == 0) {
			this->state = 0;
			tile->eating = false;
		}
		eatTimer = sf::seconds(this->eatSpeed);
	}
}

Ant::Ant() {
	Game* game = Game::getGame();
	this->speed = 100.0f;
	this->eatSpeed = 5.0f;
	this->eatTimer = sf::seconds(eatSpeed);
	this->eatRad = game->getTileSize() * 2;
	this->type = 0;
	sprite = sf::Sprite(game->antTexture);
	sprite.setPosition(sf::Vector2f(0.0f,0.0f));
	float scale = game->getTileSize() / sprite.getLocalBounds().width;
	sprite.setOrigin(sf::Vector2f((sprite.getLocalBounds().width / 2), 0));
	sprite.setScale(sf::Vector2f(scale * .75,scale * .75));
}


Ladybug::Ladybug() {
	Game* game = Game::getGame();
	this->speed = 500.0f;
	this->eatSpeed = 1.0f;
	this->eatTimer = sf::seconds(eatSpeed);
	this->eatRad = game->getTileSize();
	this->type = 1;
	sprite = sf::Sprite(game->ladybugTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	float scale = game->getTileSize() / sprite.getLocalBounds().width;
	sprite.setOrigin(sf::Vector2f((sprite.getLocalBounds().width / 2), 0));
	sprite.setScale(sf::Vector2f(scale / 2, scale / 2));
}

void Ladybug::update() {
	Game* game = Game::getGame();
	std::uniform_int_distribution<> range(-5, 5);
	int x = sprite.getPosition().x;
	int y = sprite.getPosition().y;


	sf::CircleShape circle = sf::CircleShape(eatRad);
	circle.setOrigin(game->getTileSize(), game->getTileSize());
	circle.setPosition(x, y);
	sf::FloatRect fov = circle.getGlobalBounds();

	sf::Vector2f move = sf::Vector2f(range(game->rng), range(game->rng));
	movement += move;

	if ((x > (game->getTileW() * game->getTileSize())) || (x < 0)) {
		movement.x *= -1;
	}
	if ((y > (game->getTileH() * game->getTileSize())) || (y < 0)) {
		movement.y *= -1;
	}

	if (game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->lushness == 0) {
		state = 0;
	}

	if (state == 1) {
		if (distance(target, sf::Vector2f(x, y)) >= 10) {
			movement.x = target.x - x;
			movement.y = target.y - y;
		}
		else {
			this->eat(game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize()));
			return;
		}
	}
	else {
		for (int xx = 0; xx < game->getTileW(); xx++) {
			for (int yy = 0; yy < game->getTileH(); yy++) {
				sf::Vector2f pt = sf::Vector2f((xx * game->getTileSize()) + (game->getTileSize() / 2), (yy * game->getTileSize()) + (game->getTileSize() / 2));
				if (game->getTileAt(xx, yy)->scent && distance(pt, sf::Vector2f(x, y)) <= game->getTileSize() * 3.5) {
					Tile* tile = game->getTileAt(xx, yy);
					target = pt;
					tile->startEat();
					this->state = 1;
					break;
				}
				if (fov.contains(pt) && game->getTileAt(xx, yy)->lushness >= 1 /* && !game->getTileAt(xx, yy)->eating*/) {
					Tile* tile = game->getTileAt(xx, yy);
					target = pt;
					tile->startEat();
					this->state = 1;
					break;
				}
			}
			if (state == 1)
				break;
		}
	}



	sprite.setRotation(angle(sprite.getPosition() + movement, sprite.getPosition()) - 90);
	sprite.move(normalize(movement) * game->getElapsedTime().asSeconds() * speed);
}

Stinkbug::Stinkbug() {
	Game* game = Game::getGame();
	this->speed = 50.0f;
	this->eatRad = game->getTileSize() * 3;
	this->type = 2;
	sprite = sf::Sprite(game->stinkbugTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	float scale = game->getTileSize() / sprite.getLocalBounds().width;
	sprite.setOrigin(sf::Vector2f((sprite.getLocalBounds().width / 2), 0));
	sprite.setScale(sf::Vector2f(scale / 2, scale / 2));
}

void Stinkbug::update() {
	Game* game = Game::getGame();
	std::uniform_int_distribution<> range(-5, 5);
	int x = sprite.getPosition().x;
	int y = sprite.getPosition().y;

	sf::CircleShape circle = sf::CircleShape(eatRad);
	circle.setOrigin(game->getTileSize(), game->getTileSize());
	circle.setPosition(x, y);
	sf::FloatRect fov = circle.getGlobalBounds();



	sf::Vector2f move = sf::Vector2f(range(game->rng), range(game->rng));
	movement += move;

	if ((x > (game->getTileW() * game->getTileSize())) || (x < 0)) {
		movement.x *= -1;
	}
	if ((y > (game->getTileH() * game->getTileSize())) || (y < 0)) {
		movement.y *= -1;
	}

	if ((game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->scent || 
		game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->lushness ==0) && state == 1) {
		state = 0;
	}

	if (state == 1) {
		if (distance(target, sf::Vector2f(x, y)) >= 10) {
			movement.x = target.x - x;
			movement.y = target.y - y;
		}
		else {
			game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->scent = true;
			return;
		}
	}
	else {
		for (int xx = 0; xx < game->getTileW(); xx++) {
			for (int yy = 0; yy < game->getTileH(); yy++) {
				sf::Vector2f pt = sf::Vector2f((xx * game->getTileSize()) + (game->getTileSize() / 2), (yy * game->getTileSize()) + (game->getTileSize() / 2));
				if (fov.contains(pt) && game->getTileAt(xx, yy)->lushness >= 1 && !game->getTileAt(xx, yy)->scent/* && !game->getTileAt(xx, yy)->eating*/) {
					Tile* tile = game->getTileAt(xx, yy);
					target = pt;
					this->state = 1;
					break;
				}
			}
			if (state == 1)
				break;
		}
	}



	sprite.setRotation(angle(sprite.getPosition() + movement, sprite.getPosition()) - 90);
	sprite.move(normalize(movement) * game->getElapsedTime().asSeconds() * speed);
}

void Stinkbug::stink(sf::Vector2i vec) {
	Game* game = Game::getGame();
	Tile* tile = game->getTileAt(vec.x, vec.y);

	tile->scent = true;
}


Pheremone::Pheremone(sf::Vector2f inPt, int inType) {
	this->point = inPt;
	this->type = inType;
}
