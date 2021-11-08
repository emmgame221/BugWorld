#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:	
	sf::Sprite sprite;
	void update();
	void draw();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f pos);
	void setScale(float size);
};

