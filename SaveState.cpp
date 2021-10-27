/*#include <direct.h>
#include <string>
#include <fstream>
#include <iostream>

#pragma warning(disable: 4996)

void main()
{
	std::string GetUser = getenv("USERNAME");
	std::string SaveDirectory = "C:\\Users\\" + GetUser + "\\AppData\\Local\\BugWorldSave\\save.txt";
	std::string Directory = "C:\\Users\\" + GetUser + "\\AppData\\Local\\BugWorldSave";

	const char* ConvertStringToConst = Directory.c_str();

	if (mkdir(ConvertStringToConst) == -1)
		std::cerr << "Error: " << strerror(errno) << std::endl;
	else
		std::cout << "Save File Created";

	std::ofstream SaveFile;
	
	SaveFile.open(Directory);

}*/