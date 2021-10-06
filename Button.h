#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Button : 
    public Entity
{
public:
    Button(sf::Sprite s);
    sf::FloatRect buttonRect;
    sf::RenderWindow window;
    sf::Event event;
    int onClick(int x, int y);
    
};
