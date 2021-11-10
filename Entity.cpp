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

void Entity::setScale(float size) {
	sf::FloatRect bounds = sprite.getLocalBounds();
	sf::Vector2f scale(size / bounds.width, size / bounds.height);
	sprite.setScale(scale);
}