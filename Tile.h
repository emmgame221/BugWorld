#pragma once
#include "Entity.h"
class Tile :
    public Entity
{
public:
    int lushness;
    void incLushness();
    void decLushness();
};

