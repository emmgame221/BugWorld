#include "Tile.h"
#include "Game.h"

Tile::Tile(int lushness, float x, float y, float tileSize) {
	this->lushness = lushness;
	sprite = sf::Sprite();
	sprite.setPosition(sf::Vector2f(x, y));
	sprite.setTexture(Game::getGame()->vegTextures[lushness]);
	float scale = tileSize / sprite.getLocalBounds().width;
	sprite.setScale(sf::Vector2f(scale, scale));
}

bool Tile::incLushness() {
	if (lushness == 3) {
		return false;
	}
	lushness++;
	Game* game = Game::getGame();
	game->totalVegetation++;
	sprite.setTexture(game->vegTextures[lushness]);
	return true;
}

bool Tile::decLushness() {
	if (lushness == 0) {
		return false;
	}
	lushness--;
	Game* game = Game::getGame();
	game->totalVegetation--;
	sprite.setTexture(game->vegTextures[lushness]);
	return true;
}

void Tile::startEat() {
	this->eating = true;
}

bool Tile::checkEat() {
	return eating;
}

void Tile::setSize(float size) {
	float scale = size / sprite.getLocalBounds().width;
	sprite.setScale(sf::Vector2f(scale, scale));
}

void Tile::setPosition(float x, float y) {
	sprite.setPosition(sf::Vector2f(x, y));
}