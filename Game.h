#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game
{
private:
	sf::RenderWindow window;
	std::vector<int> vegLevels;
	int food;
	int currentLevel;
	std::vector<Entity> entities;
public:
	static Game getGame();
	void draw(sf::Sprite sprite);
};

