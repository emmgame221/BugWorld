#include "Entity.h"
#include "Game.h"

void Entity::draw() {
	Game::getGame()->draw(sprite);
}

void Entity::update() {}

sf::Vector2f Entity::getPosition() {
	return sprite.getPosition();
}

void Entity::setPosition(sf::Vector2f pos) {
	sprite.setPosition(pos);
}