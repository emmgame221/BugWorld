#include "Bug.h"
#include "Game.h"
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

std::uniform_int_distribution<> range(-5, 5);



//default bug movement and food searching
void Bug::update() {
	Game* game = Game::getGame();
	int x = sprite.getPosition().x;
	int y = sprite.getPosition().y;

	sf::CircleShape circle = sf::CircleShape(visionRad);
	circle.setOrigin(game->getTileSize(), game->getTileSize());
	circle.setPosition(x,y);
	sf::FloatRect fov = circle.getGlobalBounds();

	//random movement twitch
	sf::Vector2f move = sf::Vector2f(range(game->rng), range(game->rng));
	movement += move;
	
	//check to see if out of bounds
	if ((x > (game->getTileW() * game->getTileSize())) || (x < 0)) {
		movement.x *= -1;
	}
	if ((y > (game->getTileH() * game->getTileSize())) || (y < 0)) {
		movement.y *= -1;
	}

	//checks if active target is still lush
	if (game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->lushness == 0) {
		state = searching;
		game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->eating = false;
	}

	//eat if target has already been found
	if (state == targeting) {
		if (distance(target, sf::Vector2f(x, y)) >= 10) {
			movement.x = target.x - x;
			movement.y = target.y - y;
		}
		else {
			this->eat(game->getTileAt(target.x / game->getTileSize(),target.y / game->getTileSize()));
			return;
		}
	}
	//search for new target
	else {
		for (int xx = 0; xx < game->getTileW(); xx++) {
			for (int yy = 0; yy < game->getTileH(); yy++) {
				sf::Vector2f pt = sf::Vector2f((xx * game->getTileSize()) + (game->getTileSize() / 2), (yy * game->getTileSize()) + (game->getTileSize() / 2));
				if (fov.contains(pt) && game->getTileAt(xx, yy)->lushness >= 1 /* && !game->getTileAt(xx, yy)->eating*/) {
					Tile* tile = game->getTileAt(xx, yy);
					target = pt;
					tile->eating = true;
					this->state = targeting;
					break;
				}
			}
			if (state == targeting)
				break;
		}
	}
	//apply movement and set rotation
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
			this->state = searching;
			tile->eating = false;
		}
		eatTimer = sf::seconds(this->eatSpeed);
	}
}

void Bug::increaseSpeed(float x) {
	speed += x;
}

void Bug::decreaseEatTime(float x) {
	eatSpeed -= x;
	if (eatSpeed < 0.f) {
		eatSpeed = 0.f;
	}
}

Ant::Ant() {
	Game* game = Game::getGame();
	this->speed = 100.0f + game->speedModifier;
	this->eatSpeed = 5.0f - game->eatModifier;
	this->eatTimer = sf::seconds(eatSpeed);
	this->visionRad = game->getTileSize() * 2;
	this->type = ant;
	sprite = sf::Sprite(game->antTexture);
	sprite.setPosition(sf::Vector2f(0.0f,0.0f));
	float scale = game->getTileSize() / sprite.getLocalBounds().width;
	sprite.setOrigin(sf::Vector2f((sprite.getLocalBounds().width / 2), 0));
	sprite.setScale(sf::Vector2f(scale / 2,scale / 2));
}


Ladybug::Ladybug() {
	Game* game = Game::getGame();
	this->speed = 500.0f + game->speedModifier;
	this->eatSpeed = 1.0f - game->eatModifier;
	this->eatTimer = sf::seconds(eatSpeed);
	this->visionRad = game->getTileSize();
	this->type = ladyBug;
	sprite = sf::Sprite(game->ladybugTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	float scale = game->getTileSize() / sprite.getLocalBounds().width;
	sprite.setOrigin(sf::Vector2f((sprite.getLocalBounds().width / 2), 0));
	sprite.setScale(sf::Vector2f(scale / 2, scale / 2));
}

void Ladybug::update() {
	Game* game = Game::getGame();
	int x = sprite.getPosition().x;
	int y = sprite.getPosition().y;

	sf::CircleShape circle = sf::CircleShape(visionRad);
	circle.setOrigin(game->getTileSize(), game->getTileSize());
	circle.setPosition(x, y);
	sf::FloatRect fov = circle.getGlobalBounds();

	sf::Vector2f move = sf::Vector2f(range(game->rng), range(game->rng));
	movement += move;

	if ((x > (game->getTileW() * game->getTileSize())) || (x < 0)) {
		if (x < 0)
			sprite.move(sf::Vector2f(0, -x));
		else
			sprite.move(sf::Vector2f(0, (game->getTileW() * game->getTileSize()) - x));

		movement.x *= -1;
	}
	if ((y > (game->getTileH() * game->getTileSize())) || (y < 0)) {
		if (y < 0)
			sprite.move(sf::Vector2f(0, -y));
		else
			sprite.move(sf::Vector2f(0, (game->getTileH() * game->getTileSize()) - y));

		movement.y *= -1;
	}

	x = sprite.getPosition().x;
	y = sprite.getPosition().y;

	if (game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->lushness == 0) {
		state = searching;
		game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->eating = false;
	}

	if (state == targeting) {
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
				if (game->getTileAt(xx, yy)->scent && distance(pt, sf::Vector2f(x, y)) <= game->getTileSize() * 3.5 && !game->getTileAt(xx, yy)->eating) {
					Tile* tile = game->getTileAt(xx, yy);
					target = pt;
					tile->eating = true;
					this->state = targeting;
					break;
				}
				if (fov.contains(pt) && game->getTileAt(xx, yy)->lushness >= 1  && !game->getTileAt(xx, yy)->eating) {
					Tile* tile = game->getTileAt(xx, yy);
					target = pt;
					tile->eating = true;
					this->state = targeting;
					break;
				}
			}
			if (state == targeting)
				break;
		}
	}
	sprite.setRotation(angle(sprite.getPosition() + movement, sprite.getPosition()) - 90);
	sprite.move(normalize(movement * game->getTileSize()) * game->getElapsedTime().asSeconds() * speed );
}

Stinkbug::Stinkbug() {
	Game* game = Game::getGame();
	this->speed = 150.0f + game->speedModifier;
	this->visionRad = game->getTileSize() * 3;
	this->type = stinkBug;
	sprite = sf::Sprite(game->stinkbugTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	float scale = game->getTileSize() / sprite.getLocalBounds().width;
	sprite.setOrigin(sf::Vector2f((sprite.getLocalBounds().width / 2), 0));
	sprite.setScale(sf::Vector2f(scale / 2, scale / 2));
}

void Stinkbug::update() {
	Game* game = Game::getGame();
	int x = sprite.getPosition().x;
	int y = sprite.getPosition().y;

	sf::CircleShape circle = sf::CircleShape(visionRad);
	circle.setOrigin(game->getTileSize(), game->getTileSize());
	circle.setPosition(x, y);
	sf::FloatRect fov = circle.getGlobalBounds();
	//radius checking instead
	sf::Vector2f move = sf::Vector2f(range(game->rng), range(game->rng));
	movement += move;

	if ((x > (game->getTileW() * game->getTileSize())) || (x < 0)) {
		if (x < 0)
			sprite.move(sf::Vector2f(0, -x));
		else
			sprite.move(sf::Vector2f(0, (game->getTileW() * game->getTileSize()) - x));

		movement.x *= -1;
	}
	if ((y > (game->getTileH() * game->getTileSize())) || (y < 0)) {
		if (y < 0)
			sprite.move(sf::Vector2f(0, -y));
		else
			sprite.move(sf::Vector2f(0, (game->getTileH() * game->getTileSize()) - y));

		movement.y *= -1;
	}

	x = sprite.getPosition().x;
	y = sprite.getPosition().y;


	if ((game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->scent || 
		game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->lushness ==0) && state == 1) {
		state = searching;
	}

	if (state == targeting) {
		if (distance(target, sf::Vector2f(x, y)) >= 10) {
			movement.x = target.x - x;
			movement.y = target.y - y;
		}
		else {
			game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->scent = true;
			game->getTileAt(target.x / game->getTileSize(), target.y / game->getTileSize())->scenting = false;
			return;
		}
	}
	else {
		for (int xx = 0; xx < game->getTileW(); xx++) {
			for (int yy = 0; yy < game->getTileH(); yy++) {
				sf::Vector2f pt = sf::Vector2f((xx * game->getTileSize()) + (game->getTileSize() / 2), (yy * game->getTileSize()) + (game->getTileSize() / 2));
				if (fov.contains(pt) && game->getTileAt(xx, yy)->lushness >= 1 && !game->getTileAt(xx, yy)->scent && !game->getTileAt(xx, yy)->scenting) {
					Tile* tile = game->getTileAt(xx, yy);
					tile->scenting = true;
					target = pt;
					this->state = targeting;
					break;
				}
			}
			if (state == targeting)
				break;
		}
	}
	sprite.setRotation(angle(sprite.getPosition() + movement, sprite.getPosition()) - 90);
	sprite.move(normalize(movement * game->getTileSize()) * game->getElapsedTime().asSeconds() * speed);
}



Pheremone::Pheremone(sf::Vector2f inPt, int inType) {
	this->point = inPt;
	this->type = inType;
}
