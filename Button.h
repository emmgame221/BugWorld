#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Button : 
    public Entity 
{
public:
    int click = 0;
    sf::Event event;
    sf::FloatRect buttonRect = sprite.getGlobalBounds();
    sf::RenderWindow window;
    void onClick();
    
};
