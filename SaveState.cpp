#include <direct.h>
#include <string>
#include <fstream>

#pragma warning(disable: 4996)

void main()
{
	std::string GetUser = getenv("USERNAME");
	std::string SaveDirectory = "C:\\Users\\" + GetUser + "\\AppData\\Local\\BugWorldSave\\save.txt";
	std::string Directory = "C:\\Users\\" + GetUser + "\\AppData\\Local\\BugWorldSave";
}