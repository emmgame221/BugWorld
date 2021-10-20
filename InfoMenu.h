#pragma once
#include <string>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <iostream>

class Menu {
public:
	int bugMenu();
	std::string infoString;
	sf::Text infoText;
	char ch;
	sf::Font font;
	std::ifstream inputFile;
	std::string loadInfo();
	


};
