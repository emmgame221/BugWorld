#include "ButtonSprite.h"
#include <SFML/Graphics.hpp>


Button* AllButtonSprite::antPic() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->antTexture);
	sprite.rotate(90.0f);
	sprite.setPosition(sf::Vector2f(82.0f, 836.0f));
	Button* b = new Button(sprite);
	return b;
}

Button* AllButtonSprite::plusAnt() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->plusTexture);
	sprite.scale(2, 2);
	sprite.setPosition(sf::Vector2f(500.0f, 500.0f));
	Button* b = new Button(sprite);
	return b;
}

Button* AllButtonSprite::minusAnt() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->minusTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	Button* b = new Button(sprite);
	return b;
}

Button* AllButtonSprite::ladybugPic() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->ladybugTexture);
	sprite.scale(2, 2);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	Button* b = new Button(sprite);
	return b;
}

Button* AllButtonSprite::plusLadybug() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->plusTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	Button* b = new Button(sprite);
	return b;
}

Button* AllButtonSprite::minusLadybug() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->minusTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 0.0f));
	Button* b = new Button(sprite);
	return b;
}