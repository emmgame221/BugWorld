#pragma once
#include "Entity.h"
#include "Tile.h"
#include "Bug.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <random>

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
	float sfxVolume = 50.f;
	float bgmVolume = 50.f;
	sf::Time elapsedTime;
	sf::Clock clock;
	sf::Time growthTimer = sf::seconds(1.f);
	int gridWidth;
	int gridHeight;
	float tileSize;
	sf::Font font;
	sf::Text foodText;
	sf::Text levelText;

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
	void addFood(int f);
	void setGridSize(int width, int height);
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
	void vegGrowth();
	int countAdjVeg(int x, int y);
	int totalLushness();
	Tile* getTileAt(int x, int y);
};