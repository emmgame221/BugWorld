#pragma once
#include "Entity.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game
{
private:
	static Game* game;
	sf::RenderWindow* window;
	sf::Texture dirtTexture;
	sf::Texture veg1Texture;
	sf::Texture veg2Texture;
	sf::Texture veg3Texture;
	int gridWidth;
	int gridHeight;
	float tileSize;
	int food;
	int currentLevel;
	std::vector<Entity> entities;
	std::vector<Tile> tiles;
	std::vector<Entity> buttons;
public:
	static Game* getGame();
	void drawAll();
	void draw(sf::Sprite sprite);
	void update(sf::Event event);
	void addFood(int f);
	void setGridSize(int width, int height);
};

