#include "Game.h"

Game::Game() {
	this->setGridSize(10, 10);
	std::vector<Tile*> tiles;
	this->tiles = tiles;
	std::vector<Entity*> entities;
	this->entities = entities;
	std::vector<Entity*> buttons;
	this->buttons = buttons;
	food = 0;
	currentLevel = 1;
	vegTextures[0] = new sf::Texture();
	vegTextures[1] = new sf::Texture();
	vegTextures[2] = new sf::Texture();
	vegTextures[3] = new sf::Texture();
	vegTextures[0]->loadFromFile("./resources/dirt.png");
	vegTextures[1]->loadFromFile("./resources/veg1.png");
	vegTextures[2]->loadFromFile("./resources/veg2.png");
	vegTextures[3]->loadFromFile("./resources/veg3.png");
	for (int i = 0; i < gridWidth; i++) {
		for (int j = 0; j < gridHeight; j++) {
			tiles.push_back(new Tile(0, i * tileSize, j * tileSize));
		}
	}
}

Game* Game::getGame() {
	if (game == nullptr) {
		game = new Game();
	}
	return game;
}

void Game::drawAll() {
	for (int i = 0; i < tiles.size(); i++) {
		tiles[i]->draw();
	}
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->draw();
	}
	for (int i = 0; i < buttons.size(); i++) {
		buttons[i]->draw();
	}
}

void Game::draw(sf::Sprite sprite) {
	window->draw(sprite);
}

void Game::update(sf::Event event) {
	for (int i = 0; i < entities.size(); i++) {
		entities[i]->update();
	}
}

void Game::addFood(int f) {
	food += f;
}

void Game::setGridSize(int width, int height) {
	gridWidth = width;
	gridHeight = height;
	sf::Vector2u windowSize = (window == nullptr) ? sf::Vector2u(1440, 1080) : window->getSize();
	float gameWorldWidth = windowSize.x * 0.9f;
	float gameWorldHeight = windowSize.y * 0.9f;
	float tileWidth = gameWorldWidth / gridWidth;
	float tileHeight = gameWorldHeight / gridHeight;
	tileSize = (tileWidth > tileHeight) ? tileHeight : tileWidth;
}

void Game::setWindow(sf::RenderWindow* win) {
	window = win;
}

sf::Texture* Game::getVegTexture(int lushness) {
	if (lushness < 0 || lushness > 3) {
		return vegTextures[0];
	}
	return vegTextures[lushness];
}

Game* Game::game = NULL;