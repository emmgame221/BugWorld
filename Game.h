#pragma once
#include "Entity.h"
#include "Tile.h"
#include "Bug.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	float sfxVolume = 0.5f;
	float bgmVolume = 0.5f;
	sf::Time elapsedTime;
	sf::Clock clock;
	sf::Time growthTimer = sf::seconds(1.f);
	int gridWidth;
	int gridHeight;
	float tileSize;
	int food = 0;
	int currentLevel = 1;
	int totalBugs = 0;

	std::vector<Entity*> entities;
	std::vector<Entity*> tiles;
	std::vector<Entity*> buttons;
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
	sf::Time getElapsedTime();
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
	void increaseSFXVolume();
	void decreaseSFXVolume();
	void increaseBGMVolume();
	void decreaseBGMVolume();
	void playSpawnSound();
	void playPrestigeSound();
	void spawnButtons();
	void vegGrowth();
};