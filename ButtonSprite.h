#pragma once
#include "Entity.h"
#include "Game.h"
#include "Button.h"
#include <functional>
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
	static Button* saveButton();
	static Button* loadButton();
	static Button* prestigeButton();
	static Button* eatUpButton();
	static Button* speedUpButton();
};
