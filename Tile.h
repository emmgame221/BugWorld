#pragma once
#include "Entity.h"

class Tile :
    public Entity
{
public:
    Tile(int lushness, float x, float y, float tileSize);
    int lushness;
    void incLushness();
    void decLushness();
};

