#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
private:
	sf::Sprite sprite;

public:
	void update();
	void draw();
};

