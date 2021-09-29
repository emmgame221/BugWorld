#include <iostream>
#include <fstream>
#include "Game.h"
#include "Tile.h"
#include "Entity.h"


void save() {
	char letter = "a";

	ofstream save_file;;
	save_file.open("SaveFile.txt");
	save_file << letter;
	save_file.close();
	return 0;

	//ofstream out("C:\\Users\\Adr\\source\\repos\\BugWorld\\Save Files", ofstream::app);

	//out << letter << endl;
	//out.close();
}