#pragma once
#include "Entity.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <string>

class Bug :
    public Entity
{
protected:
    float speed;
    float eatSpeed;
    sf::Time eatTimer;
    int state = 0; //0-searching 1-go to target 2-return
    sf::Vector2f movement = sf::Vector2f(1.0f, 1.0f);
    sf::Vector2f target;
    float eatRad;
public:
    int type;
    virtual void update();
    void eat(Tile*);
    void increaseSpeed(float x);
    void decreaseEatTime(float x);
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
    void update();
};

class Stinkbug :
    public Bug
{
public:
    Stinkbug();
    void update();
    void stink(sf::Vector2i);
};

class Pheremone
{
public:
    sf::Vector2f point;
    int type; 
    Pheremone(sf::Vector2f,int);
};