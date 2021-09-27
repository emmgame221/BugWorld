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
	int food;
	int currentLevel;
	std::vector<Entity> entities;
public:
	static Game* getGame();
	void draw(sf::Sprite sprite);
};

