#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>
#include "Game.h"
#include "Tile.h"
#include "Entity.h"
#pragma warning(disable: 4996)

void main() {
	// Get environment name
	std::string get_user = getenv("USERNAME");
	std::string save_directory = string save_directory = "C:\\Users\\" + get_user + "\\AppData\\Local\\BugWorldSave\\save.txt";
	std::string directory = "C:\\Users\\" + get_user + "\\AppData\\Local\\BugWorldSave";

	const char* conver_dir_to_const = directory.c_str();
	if (mkdir(conver_dir_to_const) == -1)
		std::cerr << "Error: " << strerror(errno) << std::endl;
	else
		std::cout << "File created" << std::endl;

	ofstream save_file;
	save_file.open(save_directory);

	save_file << "Writing to file.." << std::endl;
	save_file.close();

	return 0;
}

