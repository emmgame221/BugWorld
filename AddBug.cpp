#include "Button.h"
#include "Game.h"
#include "Entity.h"
#include "AddBug.h"

void AddBug::Add() {
	if (food < bugCost) {
		return;
	}
	food -= bugCost;
	totalBug += 1;
	//Push_Back Overloaded for unknown reason
	//spriteVector.push_back(sprite);
}

void AddBug::Subtract() {
	if (totalBug >= 1) {
		spriteVector.pop_back();
		food += bugSellCost;
		totalBug -= 1;
	}
	return;
}