#pragma once
#include "Entity.h"
#include "Game.h"
#include "Button.h"
#include <string>
#include <SFML/Graphics.hpp>

class AllButtonSprite : public Entity, protected Game {
	
public:
    Button* antPic();
	Button* plusAnt();
	Button* minusAnt();
	Button* ladybugPic();
	Button* plusLadybug();
	Button* minusLadybug();
};
