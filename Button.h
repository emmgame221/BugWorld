#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Button {
    sf::FloatRect buttonRect = sprite.getGlobalBounds();
public:
    void onClick();
    
};
