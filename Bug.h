#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <string>

class Bug :
    public Entity
{
protected:
    float speed;
    float eatSpeed;
    int state = 0; //0-searching 1-go to target 2-return
    sf::Vector2f movement = sf::Vector2f(1.0f, 1.0f);
public:
    int type;
    void update();
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

class Pheremone
{
public:
    sf::Vector2f point;
    int type; 
    Pheremone(sf::Vector2f,int);
};