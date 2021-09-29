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
	sf::Texture vegTextures[4];
	int gridWidth;
	int gridHeight;
	float tileSize;
	int food;
	int currentLevel;
	std::vector<Entity*> entities;
	std::vector<Tile*> tiles;
	std::vector<Entity*> buttons;
public:
	static Game* getGame();
	void setWindow(sf::RenderWindow* win);
	void drawAll();
	void draw(sf::Sprite sprite);
	void update(sf::Event event);
	void addFood(int f);
	void setGridSize(int width, int height);
	void createTiles();
	sf::Texture getVegTexture(int lushness);
};