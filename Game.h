#pragma once
#include "Entity.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game
{
private:
	Game();
	static Game* game;
	sf::RenderWindow* window;
	int gridWidth;
	int gridHeight;
	float tileSize;
	int food;
	int currentLevel;
	std::vector<Entity*> entities;
	std::vector<Entity*> tiles;
	std::vector<Entity*> buttons;
public:
	sf::Texture vegTextures[4];
	static Game* getGame();
	void setWindow(sf::RenderWindow* win);
	void drawAll();
	void draw(sf::Sprite sprite);
	void update(sf::Event event);
	void addFood(int f);
	void setGridSize(int width, int height);
	void createTiles();
};