#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <functional>

class Button : 
    public Entity
{
private:
    std::function<void()> toCall;
    float xOffset; // These offsets and sizes are a percentage of screen size
    float yOffset;
    float xSize;
    float ySize;
public:
    Button(sf::Sprite s, std::function<void()> func, float xOffset, float yOffset, float xSize, float ySize);
    void onClick();
    void updateTransform();
};
