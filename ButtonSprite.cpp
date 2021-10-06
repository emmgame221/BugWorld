#include "ButtonSprite.h"
#include <SFML/Graphics.hpp>


Button* AllButtonSprite::antPic() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->antTexture);
	sprite.rotate(90.0f);
	sprite.setPosition(sf::Vector2f(82.0f, 836.0f));
	Button* b = new Button();
	b->sprite = sprite;
	return b;
}

Button* AllButtonSprite::plusAnt() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->plusTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 912.0f));
	Button* b = new Button();
	b->sprite = sprite;
	return b;
}

Button* AllButtonSprite::minusAnt() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->minusTexture);
	sprite.setPosition(sf::Vector2f(0.0f, 963.0f));
	Button* b = new Button();
	b->sprite = sprite;
	return b;
}

Button* AllButtonSprite::ladybugPic() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->ladybugTexture);
	sprite.scale(1.7, 1.7);
	sprite.rotate(90.0f);
	sprite.setPosition(sf::Vector2f(150.0f, 864.0f));
	Button* b = new Button();
	b->sprite = sprite;
	return b;
}

Button* AllButtonSprite::plusLadybug() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->plusTexture);
	sprite.setPosition(sf::Vector2f(100.0f, 912.0f));
	Button* b = new Button();
	b->sprite = sprite;
	return b;
}

Button* AllButtonSprite::minusLadybug() {
	Game* game = Game::getGame();
	sprite = sf::Sprite(game->minusTexture);
	sprite.setPosition(sf::Vector2f(100.0f, 963.0f));
	Button* b = new Button();
	b->sprite = sprite;
	return b;
}