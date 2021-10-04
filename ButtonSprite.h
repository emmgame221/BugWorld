#pragma once
#include "Entity.h"
#include "Game.h"
#include "Button.h"
#include <string>
#include <SFML/Graphics.hpp>

class AllButtonSprite : public Entity, protected Game {
	
public:
    Button* antPic();
	void plusAnt();
	void minusAnt();
	void ladybugPic();
	void plusLadybug();
	void minusLadybug();
};
