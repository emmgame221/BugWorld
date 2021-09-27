#include "Game.h"

Game* Game::getGame() {
	if (game == nullptr) {
		game = new Game();
	}
	return game;
}

void Game::draw(sf::Sprite sprite) {
	window->draw(sprite);
}