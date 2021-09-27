#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game
{
private:
	static Game* game;
	sf::RenderWindow* window;
	std::vector<int> vegLevels;
	int gridWidth;
	int gridHeight;
	float tileSize;
	int food;
	int currentLevel;
	std::vector<Entity> entities;
	std::vector<Entity> tiles;
	std::vector<Entity> buttons;
public:
	static Game* getGame();
	void drawAll();
	void draw(sf::Sprite sprite);
	void update(sf::Event event);
	void setFood(int f);
	void setGridSize(int width, int height);
	void reduceVegLevel(int x, int y);
};

