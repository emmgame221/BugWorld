#include "ButtonSprite.h"

Button* AllButtonSprite::antPic() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->antTexture);
	std::function<void()> func = []() {}; // This button doesn't do anything
	float xofs = 0.f;
	float yofs = 0.9f;
	float xsize = 0.05f;
	float ysize = 0.1f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::plusAnt() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->plusTexture);
	std::function<void()> func = std::bind(&Game::spawnAnt, game);
	float xofs = 0.05f;
	float yofs = 0.9f;
	float xsize = 0.05f;
	float ysize = 0.05f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::minusAnt() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->minusTexture);
	std::function<void()> func = std::bind(&Game::killAnt, game);
	float xofs = 0.05f;
	float yofs = 0.95f;
	float xsize = 0.05f;
	float ysize = 0.05f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::ladybugPic() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->ladybugTexture);
	std::function<void()> func = []() {}; // This button doesn't do anything
	float xofs = 0.15f;
	float yofs = 0.9f;
	float xsize = 0.05f;
	float ysize = 0.1f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::plusLadybug() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->plusTexture);
	std::function<void()> func = std::bind(&Game::spawnLadybug, game);
	float xofs = 0.2f;
	float yofs = 0.9f;
	float xsize = 0.05f;
	float ysize = 0.05f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::minusLadybug() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->minusTexture);
	std::function<void()> func = std::bind(&Game::killLadybug, game);
	float xofs = 0.2f;
	float yofs = 0.95f;
	float xsize = 0.05f;
	float ysize = 0.05f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::stinkbugPic() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->stinkbugTexture);
	std::function<void()> func = []() {}; // This button doesn't do anything
	float xofs = 0.3f;
	float yofs = 0.9f;
	float xsize = 0.05f;
	float ysize = 0.1f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::plusStinkbug() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->plusTexture);
	std::function<void()> func = std::bind(&Game::spawnStinkbug, game);
	float xofs = 0.35f;
	float yofs = 0.9f;
	float xsize = 0.05f;
	float ysize = 0.05f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::minusStinkbug() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->minusTexture);
	std::function<void()> func = std::bind(&Game::killStinkbug, game);
	float xofs = 0.35f;
	float yofs = 0.95f;
	float xsize = 0.05f;
	float ysize = 0.05f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::saveButton() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->saveTexture);
	std::function<void()> func = std::bind(&Game::save, game);
	float xofs = 0.80f;
	float yofs = 0.90f;
	float xsize = 0.1f;
	float ysize = 0.1f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::loadButton() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->loadTexture);
	std::function<void()> func = std::bind(&Game::load, game);
	float xofs = 0.90f;
	float yofs = 0.90f;
	float xsize = 0.1f;
	float ysize = 0.1f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::prestigeButton() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->prestigeTexture);
	std::function<void()> func = std::bind(&Game::prestige, game);
	float xofs = 0.90f;
	float yofs = 0.20f;
	float xsize = 0.1f;
	float ysize = 0.1f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::eatUpButton() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->eatUpTexture);
	std::function<void()> func = std::bind(&Game::eatSpeedUp, game);
	float xofs = 0.90f;
	float yofs = 0.31f;
	float xsize = 0.1f;
	float ysize = 0.1f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}

Button* AllButtonSprite::speedUpButton() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->speedUpTexture);
	std::function<void()> func = std::bind(&Game::speedUp, game);
	float xofs = 0.90f;
	float yofs = 0.42f;
	float xsize = 0.1f;
	float ysize = 0.1f;
	Button* b = new Button(sprite, func, xofs, yofs, xsize, ysize);
	b->updateTransform();
	return b;
}