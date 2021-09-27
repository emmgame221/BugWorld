#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:	
	sf::Sprite sprite;
	void update();
	void draw();
};

