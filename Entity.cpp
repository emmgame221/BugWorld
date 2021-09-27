#include "Entity.h"
#include "Game.h"

void Entity::draw() {
	Game::getGame().draw(sprite);
}