#pragma once
#include "Entity.h"
#include "Tile.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <random>
#include <iostream>

enum bugNames {ant, ladyBug, stinkBug};
enum states {searching, targeting};

class Bug :
    public Entity
{
protected:
    float speed;
    float eatSpeed;
    sf::Time eatTimer;
    enum states state = searching;
    sf::Vector2f movement = sf::Vector2f(1.0f, 1.0f);
    sf::Vector2f target;
    float visionRad;
public:
    enum bugNames type;
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
};

class Pheremone
{
public:
    sf::Vector2f point;
    int type; 
    Pheremone(sf::Vector2f,int);
};