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

void Tile::incLushness() {
	if (lushness == 3) {
		return;
	}
	lushness++;
	Game* game = Game::getGame();
	sprite.setTexture(game->vegTextures[lushness]);
}

void Tile::decLushness() {
	if (lushness == 0) {
		return;
	}
	lushness--;
	Game* game = Game::getGame();
	sprite.setTexture(game->vegTextures[lushness]);
}