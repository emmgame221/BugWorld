#pragma once
#include "Entity.h"
#include "Game.h"
class Tile :
    public Entity
{
public:
    Tile(int lushness, float x, float y);
    int lushness;
    void incLushness();
    void decLushness();
};

