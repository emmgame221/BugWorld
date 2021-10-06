#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Button : 
    public Entity
{
public:
    int x;
    int y;
    Button(sf::Sprite s);
    sf::FloatRect buttonRect;
    int ifClick(float x, float y);
    
};
