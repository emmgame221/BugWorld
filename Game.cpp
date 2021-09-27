#include "Game.h"

Game* Game::getGame() {
	if (game == nullptr) {
		game = new Game();
	}
	return game;
}

void Game::drawAll() {
	for (Entity e : tiles) {
		e.draw();
	}
	for (Entity e : buttons) {
		e.draw();
	}
	for (Entity e : entities) {
		e.draw();
	}
}

void Game::draw(sf::Sprite sprite) {
	window->draw(sprite);
}

void Game::addFood(int f) {
	food += f;
}

void Game::setGridSize(int width, int height) {
	gridWidth = width;
	gridHeight = height;
	sf::Vector2u windowSize = window->getSize();
	float gameWorldWidth = windowSize.x * 0.9f;
	float gameWorldHeight = windowSize.y * 0.9f;
	float tileWidth = gameWorldWidth / gridWidth;
	float tileHeight = gameWorldHeight / gridHeight;
	tileSize = (tileWidth > tileHeight) ? tileHeight : tileWidth;
}