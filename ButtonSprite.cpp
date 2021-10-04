#include "ButtonSprite.h"
#include <SFML/Graphics.hpp>


Button AllButtonSprite::antPic() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->antTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	Button b;
	b.sprite = sprite;
	return b;
	//button.push_back(sprite);
}

void AllButtonSprite::plusAnt() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->plusTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	//button.push_back(sprite);
}

void AllButtonSprite::minusAnt() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->minusTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	//button.push_back(sprite);
}

void AllButtonSprite::ladybugPic() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->ladybugTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	//button.push_back(sprite);
}

void AllButtonSprite::plusLadybug() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->plusTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	//button.push_back(sprite);
}

void AllButtonSprite::minusLadybug() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->minusTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	//button.push_back(sprite);
}