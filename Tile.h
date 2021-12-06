#pragma once
#include "Entity.h"

class Tile :
    public Entity

{
public:
    Tile(int lushness, float x, float y, float tileSize);
    int lushness;
    bool eating = false;
    bool scent = false;
    bool scenting = false;
    bool incLushness();
    bool decLushness();
    void setSize(float size);
    void setPosition(float x, float y);
};

