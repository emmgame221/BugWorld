#pragma once
#include "Entity.h"
#include "Game.h"
#include "Button.h"
#include <functional>
#include <string>
#include <SFML/Graphics.hpp>

class AllButtonSprite {
	
public:
    static Button* antPic();
	static Button* plusAnt();
	static Button* minusAnt();
	static Button* ladybugPic();
	static Button* plusLadybug();
	static Button* minusLadybug();
	static Button* stinkbugPic();
	static Button* plusStinkbug();
	static Button* minusStinkbug();
	static Button* foodCount();
	static Button* levelCount();
};
