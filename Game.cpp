#include "Game.h"
#include "Bug.h"
#include "ButtonSprite.h"

Game::Game() {
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
	ladybugTexture.loadFromFile("./resources/ladybug.png");
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
	urd01 = std::uniform_real_distribution<float>(0.f, 1.f);
	font = sf::Font();
	font.loadFromFile("./resources/NewYork.otf");
	foodText = sf::Text("Food: " + std::to_string(food), font);
	foodText.setFillColor(sf::Color::Black);
	foodText.setPosition(sf::Vector2f(1300.f, 0.f));
	levelText = sf::Text("Level: " + std::to_string(currentLevel), font);
	levelText.setFillColor(sf::Color::Black);
	levelText.setPosition(sf::Vector2f(1300.f, 50.f));
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

void Game::checkClick(int x, int y) {
	//std::cout << "Click: " << x << "," << y << std::endl;
	float gameAreaWidth = tileSize * gridWidth;
	float gameAreaHeight = tileSize * gridHeight;
	if (x < gameAreaWidth && y < gameAreaHeight) {
		// Click in the game area
		int xi = (int)(((float)x) / tileSize);
		int yi = (int)(((float)y) / tileSize);
		if (xi < gridWidth && yi < gridHeight) {
			if (getTileAt(xi, yi)->decLushness()) {
				food++;
			}
		}
	}
	else {
		// Click in the UI area
		// Check each button to see if the click is on that button
		// Once one is found trigger that button's onClick and then break
		for (Entity* b : buttons) {
			if (b->sprite.getGlobalBounds().contains(x, y)) {
				((Button*)b)->onClick();
				break;
			}
		}
	}
}

void Game::drawAll() {
	window->draw(foodText);
	window->draw(levelText);
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

void Game::update() {
	foodText.setString("Food: " + std::to_string(food));
	levelText.setString("Level: " + std::to_string(currentLevel));
	elapsedTime = clock.restart();
	growthTimer -= elapsedTime;
	if (growthTimer <= sf::Time::Zero) {
		growthTimer = sf::seconds(1.f);
		vegGrowth();
	}
	for (unsigned int i = 0; i < bugs.size(); i++) {
		bugs[i]->update();
	}

	if (totalLushness() == 0) {
		currentLevel++;
		initLevel();
	}
}

void Game::resize() {
	sf::Vector2u windowSize = (window == nullptr) ? sf::Vector2u(1440, 1080) : window->getSize();
	float gameWorldWidth = windowSize.x * 0.9f;
	float gameWorldHeight = windowSize.y * 0.9f;
	float tileWidth = gameWorldWidth / gridWidth;
	float tileHeight = gameWorldHeight / gridHeight;
	tileSize = (tileWidth > tileHeight) ? tileHeight : tileWidth;
	for (int i = 0; i < gridWidth; i++) {
		for (int j = 0; j < gridHeight; j++) {
			Tile* t = getTileAt(i, j);
			t->setSize(tileSize);
			t->setPosition(i * tileSize, j * tileSize);
		}
	}
	for (Entity* tile : tiles) {
		((Tile*)tile)->setSize(tileSize);
	}
}

void Game::addFood(int f) {
	food += f;
}

void Game::setGridSize(int width, int height) {
	gridWidth = width;
	gridHeight = height;
	widthRange = std::uniform_int_distribution<int>(0, gridWidth - 1);
	heightRange = std::uniform_int_distribution<int>(0, gridHeight - 1);
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

void Game::initLevel() {
	createTiles();
	for (int i = 0; i < currentLevel * 10; i++) {
		vegGrowth();
	}
}

void Game::createTiles() {
	for (Entity* e : tiles) {
		delete e;
	}
	tiles.clear();
	for (int i = 0; i < gridWidth; i++) {
		for (int j = 0; j < gridHeight; j++) {
			tiles.push_back(new Tile(0, i * tileSize, j * tileSize, tileSize));
		}
	}
}

float Game::getTileSize() {
	return tileSize;
}

int Game::getTileH() {
	return gridHeight;
}

int Game::getTileW(){
	return gridWidth;
}

void Game::spawnAnt() {
	if (food >= antCost) {
		bugs.push_back(new Ant());
		playSpawnSound();
		food -= antCost;
	}
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
		for (int i = bugs.size() - 1; i >= 0; i--) {
			if (bugs[i]->type == 0) {
				bugs.erase(bugs.begin() + i);
				food += antSell;
				break;
			}
		}
	}
}

void Game::killLadybug() {
	if (bugs.size() > 0) {
		for (int i = bugs.size() - 1; i >= 0; i--) {
			if (bugs[i]->type == 1) {
				bugs.erase(bugs.begin() + i);
				food += ladySell;
				break;
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
	sfxVolume += 10.f;
	if (sfxVolume > 100.f) {
		sfxVolume = 100.f;
	}
	spawnSound.setVolume(sfxVolume);
	prestigeSound.setVolume(sfxVolume);
}

void Game::decreaseSFXVolume() {
	sfxVolume -= 10.f;
	if (sfxVolume < 0.f) {
		sfxVolume = 0.f;
	}
	spawnSound.setVolume(sfxVolume);
	prestigeSound.setVolume(sfxVolume);
}

void Game::increaseBGMVolume() {
	bgmVolume += 10.f;
	if (bgmVolume > 100.f) {
		bgmVolume = 100.f;
	}
	backgroundMusic.setVolume(bgmVolume);
}

void Game::decreaseBGMVolume() {
	bgmVolume -= 10.f;
	if (bgmVolume < 0.f) {
		bgmVolume = 0.f;
	}
	backgroundMusic.setVolume(bgmVolume);
}

void Game::playSpawnSound() {
	spawnSound.play();
}

void Game::playPrestigeSound() {
	prestigeSound.play();
}

void Game::vegGrowth() {
	int growths = 0;
	int limit = currentLevel;
	int curTotal = totalLushness();
	int max = 3 * gridWidth * gridHeight;
	if (limit + curTotal > max) {
		limit = max - curTotal;
	}
	while (growths < limit) {
		int x = widthRange(rng);
		int y = heightRange(rng);
		float prob = countAdjVeg(x, y) + 1 / 27.f;
		float rand = urd01(rng);
		if (prob >= rand) {
			if (getTileAt(x, y)->incLushness()) {
				growths++;
			}
		}
	}
}

Tile* Game::getTileAt(int x, int y) {
	return (Tile*)tiles[x * gridHeight + y];
}

int Game::countAdjVeg(int x, int y) {
	int total = 0;
	total += getTileAt(x, y)->lushness;
	if (x > 0) {
		total += getTileAt(x - 1, y)->lushness;
		if (y > 0) {
			total += getTileAt(x, y - 1)->lushness;
			total += getTileAt(x - 1, y - 1)->lushness;
		}
		if (y < gridHeight - 1) {
			total += getTileAt(x, y + 1)->lushness;
			total += getTileAt(x - 1, y + 1)->lushness;
		}
	}
	if (x < gridWidth - 1) {
		total += getTileAt(x + 1, y)->lushness;
		if (y > 0) {
			total += getTileAt(x + 1, y - 1)->lushness;
		}
		if (y < gridHeight - 1) {
			total += getTileAt(x + 1, y + 1)->lushness;
		}
	}
	return total;
}

int Game::totalLushness() {
	int total = 0;
	for (Entity* t : tiles) {
		total += ((Tile*)t)->lushness;
	}
	return total;
}

Game* Game::game = NULL;