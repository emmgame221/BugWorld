#pragma once
#include "Entity.h"

class Tile :
    public Entity
{
public:
    Tile(int lushness, float x, float y, float tileSize);
    int lushness;
    bool eating = false;
    bool incLushness();
    bool decLushness();
    void startEat();
    bool checkEat();
    void setSize(float size);
    void setPosition(float x, float y);
};

