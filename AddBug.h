#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class AddBug :
	public Entity
{
public:
	float scaleFactor;
	int totalBug;
	int bugCost;
	int bugSellCost;
	int food;
	void Add();
	void Subtract();
	std::vector<sf::Sprite> spriteVector;

};

