#pragma once
#include "Entity.h"
#include "Tile.h"
#include "Bug.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game
{
private:
	static Game* game;
	sf::RenderWindow* window;
	sf::Texture vegTextures[4];
	int gridWidth;
	int gridHeight;
	float tileSize;
	int food;
	int currentLevel;
	std::vector<Pheromone> trails;
	std::vector<Entity> entities;
	std::vector<Entity> tiles;
	std::vector<Entity> buttons;
public:
	static Game* getGame();
	static void setGame(Game* game);
	Game(sf::RenderWindow* window);
	void drawAll();
	void draw(sf::Sprite sprite);
	void update(sf::Event event);
	void addFood(int f);
	void setGridSize(int width, int height);
	sf::Texture getVegTexture(int lushness);
};

