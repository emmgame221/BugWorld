#include "Tile.h"
#include "Game.h"

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