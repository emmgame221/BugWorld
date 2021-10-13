#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <functional>

class Button : 
    public Entity
{
private:
    std::function<void()> toCall;
public:
    Button(sf::Sprite s, std::function<void()> func);
    Button(sf::Text t);
    void onClick();
};
