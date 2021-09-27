#include "Game.h"

Game::Game(sf::RenderWindow* window) {
	this->window = window;
	this->setGridSize(10, 10);
	std::vector<Entity> tiles;
	this->tiles = tiles;
	std::vector<Entity> entities;
	this->entities = entities;
	std::vector<Entity> buttons;
	this->buttons = buttons;
	food = 0;
	currentLevel = 1;
	sf::Texture texture0;
	texture0.loadFromFile("./resources/dirt.png");
	sf::Texture texture1;
	texture1.loadFromFile("./resources/veg1.png");
	sf::Texture texture2;
	texture2.loadFromFile("./resources/veg2.png");
	sf::Texture texture3;
	texture3.loadFromFile("./resources/veg3.png");
	vegTextures[0] = texture0;
	vegTextures[1] = texture1;
	vegTextures[2] = texture2;
	vegTextures[3] = texture3;
}

Game* Game::getGame() {
	return game;
}

void Game::setGame(Game* game) {
	Game::game = game;
}

void Game::drawAll() {
	for (Entity t : tiles) {
		t.draw();
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

void Game::update(sf::Event event) {
	for (Entity e : entities) {
		e.update();
	}
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

sf::Texture Game::getVegTexture(int lushness) {
	if (lushness < 0 || lushness > 3) {
		return vegTextures[0];
	}
	return vegTextures[lushness];
}