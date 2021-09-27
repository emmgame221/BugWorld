#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
private:
	sf::Sprite sprite;

public:
	virtual void update() = 0;
	void draw();
};

