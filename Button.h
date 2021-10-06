#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Button : 
    public Entity
{
public:
    sf::FloatRect buttonRect = sprite.getGlobalBounds();
    sf::RenderWindow window;
    sf::Event event;
    int onClick(int x, int y);
    
};
