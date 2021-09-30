#pragma once
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Bug :
    public Entity
{
private:
    Game game;
    float speed;
    float eatSpeed;
    int state = 0;                      //0-searching 1-go to target 2-return
    int foodCap = 3;                    //most food bug can carry before returning to nest
    float searchRadius = 20.0f;         //size of the food search radius
    float trailRate = 0.5f;             //interval that the bug drops the pheromone
    sf::Vector2i activeTarget;          //grid coord of the food the bug is currently eating/going to

public:
    Bug();
    void move();
    void eat();
    int getState();
};

class Pheromone 
{
public:
    int type;
    sf::Vector2i point;
    Pheromone(sf::Vector2i,int);
}

