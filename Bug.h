#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Bug :
    public Entity
{
private:
    float speed;
    float eatSpeed;
    int state = 0; //0-searching 1-go to target 2-return

public:
    Bug();
    void move();
    void eat();
};

