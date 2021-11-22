#include "Game.h"

Game::Game() {
	std::vector<Tile*> tiles;
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
	stinkbugTexture = sf::Texture();
	plusTexture = sf::Texture();
	minusTexture = sf::Texture();
	saveTexture = sf::Texture();
	loadTexture = sf::Texture();
	antTexture.loadFromFile("./resources/ant.png");
	ladybugTexture.loadFromFile("./resources/ladybug.png");
	stinkbugTexture.loadFromFile("./resources/stinkbug.png");
	plusTexture.loadFromFile("./resources/plus.png");
	minusTexture.loadFromFile("./resources/minus.png");
	saveTexture.loadFromFile("./resources/save.png");
	loadTexture.loadFromFile("./resources/load.png");
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
		// Once one is found trigger that button's onClick
		for (Entity* b : buttons) {
			if (b->sprite.getGlobalBounds().contains(x, y)) {
				((Button*)b)->onClick();
			}
		}
	}
}

void Game::drawAll() {
	window->draw(foodText);
	window->draw(levelText);
	window->draw(antBuyText);
	window->draw(antSellText);
	window->draw(ladyBuyText);
	window->draw(ladySellText);
	window->draw(stinkBuyText);
	window->draw(stinkSellText);
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
	antBuyText.setString(": " + std::to_string(antCost));
	antSellText.setString(": " + std::to_string(antSell));
	ladyBuyText.setString(": " + std::to_string(ladyCost));
	ladySellText.setString(": " + std::to_string(ladySell));
	stinkBuyText.setString(": " + std::to_string(stinkCost));
	stinkSellText.setString(": " + std::to_string(stinkSell));
	elapsedTime = clock.restart();
	if (elapsedTime > sf::milliseconds(50)) {
		elapsedTime = sf::milliseconds(50);
	}
	growthTimer -= elapsedTime;
	if (growthTimer <= sf::Time::Zero && totalVegetation >= 5) {
		growthTimer = sf::seconds(GROWTH_SECS);
		vegGrowth(currentLevel);
	}
	if (totalVegetation < 5) {
		lowVegTimer -= elapsedTime;
		if (lowVegTimer <= sf::Time::Zero) {
			lowVegTimer = sf::seconds(LOW_VEG_SECS);
			growthTimer = sf::seconds(GROWTH_SECS);
			vegGrowth(currentLevel);
		}
	}
	for (unsigned int i = 0; i < bugs.size(); i++) {
		bugs[i]->update();
	}
	for (unsigned int i = 0; i < tiles.size(); i++) {
		if (tiles[i]->scent) {
			tiles[i]->sprite.setColor(sf::Color(255, 0, 0));
		}
		if (tiles[i]->lushness == 0 && tiles[i]->scent) {
			tiles[i]->sprite.setColor(sf::Color(255, 255, 255));
			tiles[i]->scent = false;
		}
	}
	if (totalVegetation == 0) {
		nextLevel();
	}
	// Enable/disable buttons as necessary
	if (food < antCost) {
		addAnt->disable();
	}
	else {
		addAnt->enable();
	}
	if (food < ladyCost) {
		addLadybug->disable();
	}
	else {
		addLadybug->enable();
	}
	if (food < stinkCost) {
		addStinkbug->disable();
	}
	else {
		addStinkbug->enable();
	}
	if (antCount < 1) {
		subAnt->disable();
	}
	else {
		subAnt->enable();
	}
	if (ladybugCount < 1) {
		subLadybug->disable();
	}
	else {
		subLadybug->enable();
	}
	if (stinkbugCount < 1) {
		subStinkbug->disable();
	}
	else {
		subStinkbug->enable();
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
	for (Entity* button : buttons) {
		((Button*)button)->updateTransform();
	}
	for (Tile* tile : tiles) {
		tile->setSize(tileSize);
	}
	foodText.setPosition(sf::Vector2f(windowSize.x * 0.9f, 0.f));
	foodText.setScale(sf::Vector2f(windowSize.x * 0.08f / foodText.getLocalBounds().width, windowSize.y * 0.08f / foodText.getLocalBounds().width));
	levelText.setPosition(sf::Vector2f(windowSize.x * 0.9f, windowSize.y * 0.1f));
	levelText.setScale(sf::Vector2f(windowSize.x * 0.08f / levelText.getLocalBounds().width, windowSize.y * 0.08f / levelText.getLocalBounds().width));
	antBuyText.setPosition(sf::Vector2f(windowSize.x * 0.1f, windowSize.y * 0.9f));
	antBuyText.setScale(sf::Vector2f(windowSize.x * 0.04f / antBuyText.getLocalBounds().width, windowSize.y * 0.04f / antBuyText.getLocalBounds().width));
	antSellText.setPosition(sf::Vector2f(windowSize.x * 0.1f, windowSize.y * 0.95f));
	antSellText.setScale(sf::Vector2f(windowSize.x * 0.04f / antSellText.getLocalBounds().width, windowSize.y * 0.04f / antSellText.getLocalBounds().width));
	ladyBuyText.setScale(sf::Vector2f(windowSize.x * 0.04f / ladyBuyText.getLocalBounds().width, windowSize.y * 0.04f / ladyBuyText.getLocalBounds().width));
	for (Bug* bug : bugs) {
		sf::Vector2f lastPos = bug->getPosition();
		bug->setPosition(sf::Vector2f(lastPos.x * windowSize.x / prevWinSize.x, lastPos.y * windowSize.y / prevWinSize.y));
		bug->setScale(tileSize / 2.f);
	}
	prevWinSize = windowSize;
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
	prevWinSize = window->getSize();
}

void Game::nextLevel() {
	currentLevel++;
	if (expansion < 2 && gridWidth < MAX_GRID_WIDTH) {
		setGridSize(gridWidth + 1, gridHeight);
		expansion = (gridHeight < MAX_GRID_HEIGHT) ? expansion + 1 : 0;
	}
	else if (gridHeight < MAX_GRID_HEIGHT) {
		setGridSize(gridWidth, gridHeight + 1);
		expansion = 0;
	}
	initLevel();
}

void Game::initLevel() {
	createTiles();
	resize();
	int maxVeg = 3 * gridWidth * gridHeight;
	vegGrowth(maxVeg / 2);
}

void Game::createTiles() {
	for (Entity* e : tiles) {
		delete e;
	}
	tiles.clear();
	totalVegetation = 0;
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
		antCount++;
	}
}

void Game::spawnLadybug() {
	if (food >= ladyCost) {
		bugs.push_back(new Ladybug());
		playSpawnSound();
		food -= ladyCost;
		ladybugCount++;
	}
}

void Game::spawnStinkbug() {
	if (food >= stinkCost) {
		bugs.push_back(new Stinkbug());
		playSpawnSound();
		food -= stinkCost;
		stinkbugCount++;
	}
}


void Game::killAnt() {
	if (bugs.size() > 0) {
		for (int i = bugs.size() - 1; i >= 0; i--) {
			if (bugs[i]->type == 0) {
				bugs.erase(bugs.begin() + i);
				food += antSell;
				antCount--;
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
				ladybugCount--;
				break;
			}
		}
	}
}

void Game::killStinkbug() {
	if (bugs.size() > 0) {
		for (int i = bugs.size() - 1; i >= 0; i--) {
			if (bugs[i]->type == 2) {
				bugs.erase(bugs.begin() + i);
				food += stinkSell;
				stinkbugCount--;
				break;
			}
		}
	}
}

void Game::spawnButtons() {
	AllButtonSprite allButtons;
	buttons.push_back(allButtons.antPic());
	addAnt = allButtons.plusAnt();
	subAnt = allButtons.minusAnt();
	addLadybug = allButtons.plusLadybug();
	subLadybug = allButtons.minusLadybug();
	addStinkbug = allButtons.plusStinkbug();
	subStinkbug = allButtons.minusStinkbug();
	buttons.push_back(addAnt);
	buttons.push_back(subAnt);
	buttons.push_back(addLadybug);
	buttons.push_back(subLadybug);
	buttons.push_back(addStinkbug);
	buttons.push_back(subStinkbug);
	buttons.push_back(allButtons.ladybugPic());
	buttons.push_back(allButtons.stinkbugPic());
	buttons.push_back(allButtons.saveButton());
	buttons.push_back(allButtons.loadButton());
}

void Game::spawnLabels() {
	sf::Vector2u winSize = window->getSize();
	foodText = sf::Text("Food: " + std::to_string(food), font);
	foodText.setFillColor(sf::Color::Black);
	foodText.setPosition(sf::Vector2f(winSize.x * 0.9f, 0.f));
	foodText.setScale(sf::Vector2f(winSize.x * 0.08f / foodText.getLocalBounds().width, winSize.y * 0.08f / foodText.getLocalBounds().width));
	levelText = sf::Text("Level: " + std::to_string(currentLevel), font);
	levelText.setFillColor(sf::Color::Black);
	levelText.setPosition(sf::Vector2f(winSize.x * 0.9f, winSize.y * 0.1f));
	levelText.setScale(sf::Vector2f(winSize.x * 0.08f / levelText.getLocalBounds().width, winSize.y * 0.08f / levelText.getLocalBounds().width));
	antBuyText = sf::Text(": " + std::to_string(antCost), font);
	antBuyText.setFillColor(sf::Color::Black);
	antBuyText.setPosition(sf::Vector2f(winSize.x * 0.1f, winSize.y * 0.9f));
	antBuyText.setScale(sf::Vector2f(winSize.x * 0.04f / antBuyText.getLocalBounds().width, winSize.y * 0.04f / antBuyText.getLocalBounds().width));
	antSellText = sf::Text(": " + std::to_string(antSell), font);
	antSellText.setFillColor(sf::Color::Black);
	antSellText.setPosition(sf::Vector2f(winSize.x * 0.1f, winSize.y * 0.95f));
	antSellText.setScale(sf::Vector2f(winSize.x * 0.04f / antSellText.getLocalBounds().width, winSize.y * 0.04f / antSellText.getLocalBounds().width));
}

void Game::increaseSFXVolume() {
	sfxVolume += VOL_INC;
	if (sfxVolume > MAX_VOL) {
		sfxVolume = MAX_VOL;
	}
	spawnSound.setVolume(sfxVolume);
	prestigeSound.setVolume(sfxVolume);
}

void Game::decreaseSFXVolume() {
	sfxVolume -= VOL_INC;
	if (sfxVolume < MIN_VOL) {
		sfxVolume = MIN_VOL;
	}
	spawnSound.setVolume(sfxVolume);
	prestigeSound.setVolume(sfxVolume);
}

void Game::increaseBGMVolume() {
	bgmVolume += VOL_INC;
	if (bgmVolume > MAX_VOL) {
		bgmVolume = MAX_VOL;
	}
	backgroundMusic.setVolume(bgmVolume);
}

void Game::decreaseBGMVolume() {
	bgmVolume -= VOL_INC;
	if (bgmVolume < MIN_VOL) {
		bgmVolume = MIN_VOL;
	}
	backgroundMusic.setVolume(bgmVolume);
}

void Game::playSpawnSound() {
	spawnSound.play();
}

void Game::playPrestigeSound() {
	prestigeSound.play();
}

void Game::vegGrowth(int limit) {
	int growths = 0;
	int curTotal = totalVegetation;
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
	if (x >= gridWidth || y >= gridHeight) {
		return (Tile*)tiles[(gridWidth - 1) * gridHeight + gridHeight - 1];
	}
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

sf::Vector2u Game::getWindowSize() {
	return window->getSize();
}

namespace fs = std::filesystem;

void Game::save() {
	// Get user info
	std::string getUser = getenv("USERNAME");
#ifdef _WIN32
	fs::path filename = "C:\\Users\\" + getUser + "\\AppData\\Local\\BugWorld\\save.txt";
	fs::path directory = "C:\\Users\\" + getUser + "\\AppData\\Local\\BugWorld";
#endif
#ifdef __linux__
	fs::path filename = "/.BugWorld/save.txt";
	fs::path directory = "/.BugWorld/";
#endif
	std::ofstream out;
	// Create the save directory if necessary and open the save file to write to
	try
	{
		fs::create_directory(directory);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Failed to create directory: " << directory << std::endl;
		return;
	}
	try
	{
		out = std::ofstream(filename);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Failed to create save file: " << filename << std::endl;
		return;
	}
	// Write the values to the file
	out << std::to_string(food) << std::endl;
	out << std::to_string(currentLevel) << std::endl;
	out << std::to_string(antCount) << std::endl;
	out << std::to_string(ladybugCount) << std::endl;
	out << std::to_string(stinkbugCount) << std::endl;
	out << std::to_string(gridWidth) << std::endl;
	out << std::to_string(gridHeight) << std::endl;

	out.close();
}

void Game::load() {
	// Get user info
	std::string getUser = getenv("USERNAME");
	fs::path filename = "C:\\Users\\" + getUser + "\\AppData\\Local\\BugWorld\\save.txt";
	fs::path directory = "C:\\Users\\" + getUser + "\\AppData\\Local\\BugWorld";
	if (!fs::exists(directory) || !fs::exists(filename)) {
		std::cerr << "Attempted to load with no save file" << std::endl;
		return;
	}
	// Read in the values from the file
	std::ifstream in(filename);

	in >> food;
	in >> currentLevel;
	in >> antCount;
	in >> ladybugCount;
	in >> stinkbugCount;
	int width;
	int height;
	in >> width;
	in >> height;

	in.close();

	// Fix everything to match loaded values
	for (Bug* bug : bugs) {
		delete bug;
	}
	bugs.clear();
	for (int i = 0; i < antCount; i++) {
		bugs.push_back(new Ant());
	}
	for (int i = 0; i < ladybugCount; i++) {
		bugs.push_back(new Ladybug());
	}
	for (int i = 0; i < stinkbugCount; i++) {
		bugs.push_back(new Stinkbug());
	}
	setGridSize(width, height);
	initLevel();
}

void Game::prestige() {
	food = 0;
	currentLevel = 1;
	expansion = 0;
	totalVegetation = 0;
	totalBugs = 0;
	for (Bug* bug : bugs) {
		delete bug;
	}
	bugs.clear();
	setGridSize(START_GRID_WIDTH, START_GRID_HEIGHT);
	initLevel();
	prestigeCount += 1;
	gold += 1;
	playPrestigeSound();
}
  
Game* Game::game = NULL;