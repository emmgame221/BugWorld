#include "ButtonSprite.h"
#include <SFML/Graphics.hpp>

Button* AllButtonSprite::antPic() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->antTexture);
	sprite.rotate(90.0f);
	sprite.setPosition(sf::Vector2f(82.0f, 836.0f));
	std::function<void()> func = []() {}; // This button doesn't do anything
	Button* b = new Button(sprite, func);
	return b;
}

Button* AllButtonSprite::plusAnt() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->plusTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 912.0f));
	std::function<void()> func = std::bind(&Game::spawnAnt, game);
	Button* b = new Button(sprite, func);
	return b;
}

Button* AllButtonSprite::minusAnt() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->minusTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 965.0f));
	std::function<void()> func = std::bind(&Game::killAnt, game);
	Button* b = new Button(sprite, func);
	return b;
}

Button* AllButtonSprite::ladybugPic() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->ladybugTexture);
	sprite.scale(2, 2);
	sprite.setPosition(sf::Vector2f(150.0f, 860.0f));
	sprite.rotate(90);
	std::function<void()> func = []() {}; // This button doesn't do anything
	Button* b = new Button(sprite, func);
	return b;
}

Button* AllButtonSprite::plusLadybug() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->plusTexture);
	sprite.setPosition(sf::Vector2f(95.0f, 912.0f));
	std::function<void()> func = std::bind(&Game::spawnLadybug, game);
	Button* b = new Button(sprite, func);
	return b;
}

Button* AllButtonSprite::minusLadybug() {
	Game* game = Game::getGame();
	sf::Sprite sprite(game->minusTexture);
	sprite.setPosition(sf::Vector2f(95.0f, 965.0f));
	std::function<void()> func = std::bind(&Game::killLadybug, game);
	Button* b = new Button(sprite, func);
	return b;
}