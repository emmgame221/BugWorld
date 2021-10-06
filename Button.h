#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Button : 
    public Entity
{
public:
    int x;
    int y;
    sf::FloatRect buttonRect = sprite.getGlobalBounds();
    sf::Event event;
    int ifClick(float x, float y);
};
