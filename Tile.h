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
    bool incLushness();
    bool decLushness();
    void startEat();
    bool checkEat();
};

