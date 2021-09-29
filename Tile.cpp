#include "Tile.h"

Tile::Tile(int lushness, float x, float y) {
	this->lushness = lushness;
	sf::Sprite s;
	sprite = s;
	s.setPosition(sf::Vector2f(x, y));
	sprite.setTexture(Game::getGame()->getVegTexture(lushness));
}

void Tile::incLushness() {
	if (lushness == 3) {
		return;
	}
	lushness++;
	Game* game = Game::getGame();
	sprite.setTexture(game->getVegTexture(lushness));
}

void Tile::decLushness() {
	if (lushness == 0) {
		return;
	}
	lushness--;
	Game* game = Game::getGame();
	sprite.setTexture(game->getVegTexture(lushness));
}