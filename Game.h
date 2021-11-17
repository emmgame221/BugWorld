#pragma once
#include "Entity.h"
#include "Tile.h"
#include "Bug.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <random>

const float GROWTH_SECS = 1.f;
const float LOW_VEG_SECS = 3.f;
const float DEFAULT_VOL = 50.f;
const float MAX_VOL = 100.f;
const float MIN_VOL = 0.f;
const float VOL_INC = 10.f;
const int MAX_GRID_WIDTH = 96;
const int MAX_GRID_HEIGHT = 49;

class Game
{
protected:
	Game();
	static Game* game;
	sf::RenderWindow* window;
	sf::Music backgroundMusic;
	sf::SoundBuffer spawnSoundBuf;
	sf::Sound spawnSound;
	sf::SoundBuffer prestigeSoundBuf;
	sf::Sound prestigeSound;
	float sfxVolume = DEFAULT_VOL;
	float bgmVolume = DEFAULT_VOL;
	sf::Time elapsedTime;
	sf::Clock clock;
	sf::Time growthTimer = sf::seconds(GROWTH_SECS);
	sf::Time lowVegTimer = sf::seconds(LOW_VEG_SECS);
	int gridWidth;
	int gridHeight;
	int expansion = 0;
	float tileSize;
	sf::Vector2u prevWinSize;
	sf::Font font;
	sf::Text foodText;
	sf::Text levelText;
	sf::Text antBuyText;
	sf::Text antSellText;
	sf::Text ladyBuyText;
	sf::Text ladySellText;
	sf::Text stinkBuyText;
	sf::Text stinkSellText;

	std::vector<Tile*> tiles;
	std::vector<Entity*> buttons;
	std::vector<Bug*> bugs;

public:
	sf::Texture vegTextures[4];
	sf::Texture antTexture;
	sf::Texture ladybugTexture;
	sf::Texture stinkbugTexture;
	sf::Texture plusTexture;
	sf::Texture minusTexture;
	int antCost = 5;
	int ladyCost = 8;
	int stinkCost = 10;
	int antSell = 3;
	int ladySell = 4;
	int stinkSell = 5;
	int food = 0;
	int currentLevel = 1;
	int totalBugs = 0;
	int totalVegetation = 0;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_real_distribution<float> urd01;
	std::uniform_int_distribution<int> widthRange;
	std::uniform_int_distribution<int> heightRange;

	static Game* getGame();
	sf::Time getElapsedTime();
	void setWindow(sf::RenderWindow* win);
	void checkClick(int x, int y);
	void drawAll();
	void draw(sf::Sprite sprite);
	void update();
	void resize();
	void addFood(int f);
	void setGridSize(int width, int height);
	void nextLevel();
	void initLevel();
	void createTiles();
	float getTileSize();
	int getTileH();
	int getTileW();
	void spawnAnt();
	void spawnLadybug();
	void spawnStinkbug();
	void killAnt();
	void killLadybug();
	void killStinkbug();
	void increaseSFXVolume();
	void decreaseSFXVolume();
	void increaseBGMVolume();
	void decreaseBGMVolume();
	void playSpawnSound();
	void playPrestigeSound();
	void spawnButtons();
	void spawnLabels();
	void vegGrowth();
	int countAdjVeg(int x, int y);
	Tile* getTileAt(int x, int y);
	sf::Vector2u getWindowSize();
};