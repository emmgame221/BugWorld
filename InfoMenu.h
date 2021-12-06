#pragma once
#include <string>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <iostream>

class Menu {
public:
	int bugMenu();
	sf::RenderWindow window;
	std::string infoString;
	sf::Text infoText;
	char ch;
	sf::Font font;
	std::ifstream inputFile;
	int stringLen;
	
};
