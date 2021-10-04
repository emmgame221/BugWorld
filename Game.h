#pragma once
#include "Entity.h"
#include "Tile.h"
#include "Bug.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game
{
protected:
	Game();
	static Game* game;
	sf::RenderWindow* window;
	int gridWidth;
	int gridHeight;
	float tileSize;
	int food;
	int currentLevel;
	int totalBugs;
	std::vector<Entity*> entities;
	std::vector<Entity*> tiles;
	std::vector<Entity*> buttons;
	std::vector<sf::Sprite> button;
	std::vector<Bug*> bugs;
public:
	sf::Texture vegTextures[4];
	sf::Texture antTexture;
	sf::Texture ladybugTexture;
	sf::Texture plusTexture;
	sf::Texture minusTexture;
	int antCost = 5;
	int ladyCost = 8;
	int antSell = 3;
	int ladySell = 4;
	static Game* getGame();
	void setWindow(sf::RenderWindow* win);
	void drawAll();
	void draw(sf::Sprite sprite);
	void update(sf::Event event);
	void addFood(int f);
	void setGridSize(int width, int height);
	void createTiles();
	float getTileSize();
	void spawnAnt();
	void spawnLadybug();
	void moveBugs();
	void killAnt();
	void killLadybug();
	void spawnButtons();
};