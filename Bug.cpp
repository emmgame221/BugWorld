#include "Bug.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

Bug::Bug() {
	this->speed = 1.0f;
	this->eatSpeed = 1.0f;
	this->state = 0;
	this->game = Game::getGame();
	
	
}

void Bug::move() {
	std::srand(sprite.getPosition().x);

	//If bug has no target, either a food or the nest, the bug searches for food by randomly turning its 
	// head then moving foward. Unless there is a "way to food" pheromone, then use that.
	if (state = 0) {
		sprite.move(sf::Vector2f(1.0f, 1.0f));
		sprite.rotate(std::rand() % 15);
	}
	//As the bug searches it leaves behind a "way back home" pheromone trail
	//If the bug finds food, eat until its foodCap is filled 
	//After foodCap is filled, use "way back home" trail to go home leaving a "way to food" trail.
}

void Bug::eat() {
}

int Bug::getState() {
	return state;
}

Pheromone::Pheromone(sf::Vector2i pt, int tp) {
	this->point = pt;
	this->type = tp;
}