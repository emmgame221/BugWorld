#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <string>

class Bug :
    public Entity
{
protected:
    float speed = 0.0f;
    float eatSpeed = 0.0f;
    int state = 0; //0-searching 1-go to target 2-return

public:
    void move();
    void eat();
};

class Ant :
    public Bug
{
public:
    Ant();
    void move();
};

class Ladybug :
    public Bug
{
public:
    Ladybug();
    void move();
};