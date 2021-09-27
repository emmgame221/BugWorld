#pragma once
#include "Entity.h"
class Tile :
    private Entity
{
public:
    int lushness;
    void incLushness();
    void decLushness();
};

