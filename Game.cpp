#include "Game.h"
#include "Bug.h"
#include "ButtonSprite.h"

Game::Game() {
	this->setGridSize(15, 10);
	std::vector<Entity*> tiles;
	this->tiles = tiles;
	std::vector<Bug*> bugs;
	this->bugs = bugs;
	std::vector<Entity*> buttons;
	this->buttons = buttons;
	vegTextures[0] = sf::Texture();
	vegTextures[1] = sf::Texture();
	vegTextures[2] = sf::Texture();
	vegTextures[3] = sf::Texture();
	vegTextures[0].loadFromFile("./resources/dirt.png");
	vegTextures[1].loadFromFile("./resources/veg1.png");
	vegTextures[2].loadFromFile("./resources/veg2.png");
	vegTextures[3].loadFromFile("./resources/veg3.png");
	antTexture = sf::Texture();
	ladybugTexture = sf::Texture();
	plusTexture = sf::Texture();
	minusTexture = sf::Texture();
	antTexture.loadFromFile("./resources/ant.png");
	ladybugTexture.loadFromFile("./resources/ladybug1spritesheet.png", sf::IntRect(2, 2, 27, 29));
	plusTexture.loadFromFile("./resources/plus.png");
	minusTexture.loadFromFile("./resources/minus.png");
	clock = sf::Clock();
	spawnSoundBuf.loadFromFile("./resources/spawnsound.wav");
	spawnSound = sf::Sound(spawnSoundBuf);
	prestigeSoundBuf.loadFromFile("./resources/prestigesound.wav");
	prestigeSound = sf::Sound(prestigeSoundBuf);
	backgroundMusic.openFromFile("./resources/bgm.wav");
	backgroundMusic.setLoop(true);
	backgroundMusic.play();
	rng = std::mt19937(rd());
}

Game* Game::getGame() {
	if (game == nullptr) {
		game = new Game();
	}
	return game;
}

sf::Time Game::getElapsedTime() {
	return elapsedTime;
}

void Game::drawAll() {
	for (unsigned int i = 0; i < tiles.size(); i++) {
		tiles[i]->draw();
	}
	for (unsigned int i = 0; i < buttons.size(); i++) {
		buttons[i]->draw();
	}
	for (unsigned int i = 0; i < bugs.size(); i++) {
		bugs[i]->draw();
	}
}

void Game::draw(sf::Sprite sprite) {
	window->draw(sprite);
}

void Game::update(sf::Event event) {
	elapsedTime = clock.restart();
	growthTimer -= elapsedTime;
	if (growthTimer <= sf::Time::Zero) {
		growthTimer = sf::seconds(1.f);
		vegGrowth();
	}
	for (unsigned int i = 0; i < bugs.size(); i++) {
		bugs[i]->update();
	}
}

void Game::addFood(int f) {
	food += f;
}

void Game::setGridSize(int width, int height) {
	gridWidth = width;
	gridHeight = height;
	sf::Vector2u windowSize = (window == nullptr) ? sf::Vector2u(1440, 1080) : window->getSize();
	float gameWorldWidth = windowSize.x * 0.9f;
	float gameWorldHeight = windowSize.y * 0.9f;
	float tileWidth = gameWorldWidth / gridWidth;
	float tileHeight = gameWorldHeight / gridHeight;
	tileSize = (tileWidth > tileHeight) ? tileHeight : tileWidth;
}

void Game::setWindow(sf::RenderWindow* win) {
	window = win;
}

void Game::createTiles() {
	for (int i = 0; i < gridWidth; i++) {
		for (int j = 0; j < gridHeight; j++) {
			tiles.push_back(new Tile(0, i * tileSize, j * tileSize, tileSize));
		}
	}
}

float Game::getTileSize() {
	return tileSize;
}


void Game::spawnAnt() {
	
		bugs.push_back(new Ant());
		playSpawnSound();
		food -= antCost;
	
}

void Game::spawnLadybug() {
	if (food >= ladyCost) {
		bugs.push_back(new Ladybug());
		playSpawnSound();
		food -= ladyCost;
	}
}


void Game::killAnt() {
	if (bugs.size() > 0) {
		for (int i = bugs.size(); i >= 0; i--) {
			if (bugs[i]->type == 0) {
				bugs.erase(bugs.begin() + i);
				food += antSell;
			}
		}
	}
}

void Game::killLadybug() {
	if (bugs.size() > 0) {
		for (int i = bugs.size(); i >= 0; i--) {
			if (bugs[i]->type == 1) {
				bugs.erase(bugs.begin() + i);
				food += ladySell;
			}
		}
	}
}

void Game::spawnButtons() {
	AllButtonSprite allButtons;
	buttons.push_back(allButtons.antPic());
	buttons.push_back(allButtons.plusAnt());
	buttons.push_back(allButtons.minusAnt());
	buttons.push_back(allButtons.ladybugPic());
	buttons.push_back(allButtons.plusLadybug());
	buttons.push_back(allButtons.minusLadybug());
}

void Game::increaseSFXVolume() {
	sfxVolume += 0.1f;
	if (sfxVolume > 1.f) {
		sfxVolume = 1.f;
	}
	spawnSound.setVolume(sfxVolume);
	prestigeSound.setVolume(sfxVolume);
}

void Game::decreaseSFXVolume() {
	sfxVolume -= 0.1f;
	if (sfxVolume < 0.f) {
		sfxVolume = 0.f;
	}
	spawnSound.setVolume(sfxVolume);
	prestigeSound.setVolume(sfxVolume);
}

void Game::increaseBGMVolume() {
	bgmVolume += 0.1f;
	if (bgmVolume > 1.f) {
		bgmVolume = 1.f;
	}
}

void Game::decreaseBGMVolume() {
	bgmVolume -= 0.1f;
	if (bgmVolume < 0.f) {
		bgmVolume = 0.f;
	}
}

void Game::playSpawnSound() {
	spawnSound.play();
}

void Game::playPrestigeSound() {
	prestigeSound.play();
}

void Game::vegGrowth() {
	int growths = 0;
	while (growths < currentLevel) {

	}
}

Game* Game::game = NULL;