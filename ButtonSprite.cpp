#include "ButtonSprite.h"

Button* AllButtonSprite::antPic() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->antTexture);
	std::function<void()> func = []() {}; // This button doesn't do anything
	float xofs = 0.05f;
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
	float xofs = 0.f;
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
	float xofs = 0.f;
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
	float xofs = 0.1f;
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
	float xofs = 0.1f;
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
	sprite.scale(2, 2);
	sprite.setPosition(sf::Vector2f(218.0f, 860.0f));
	sprite.rotate(90);
	std::function<void()> func = []() {}; // This button doesn't do anything
	Button* b = new Button(sprite, func);
	return b;
}

Button* AllButtonSprite::plusStinkbug() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->plusTexture);
	sprite.setPosition(sf::Vector2f(190.0f, 912.0f));
	std::function<void()> func = std::bind(&Game::spawnStinkbug, game);
	Button* b = new Button(sprite, func);
	return b;
}

Button* AllButtonSprite::minusStinkbug() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->minusTexture);
	sprite.setPosition(sf::Vector2f(190.0f, 965.0f));
	std::function<void()> func = std::bind(&Game::killStinkbug, game);
	Button* b = new Button(sprite, func);
	return b;
}