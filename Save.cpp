#include <iostream>
#include <direct.h>
#include <string>
#include <fstream>

#pragma warning(disable: 4996)

using namespace std;

// Prototypes
//////////////////////////////////////////////////////////
void add_to_file(string directory);
void create_directory();

//////////////////////////////////////////////////////////


void main() {

	create_directory();

	return;
}

void create_directory() {
	// Get User info and set directories
	//////////////////////////////////////////////////////////
	string get_user = getenv("USERNAME");
	string save_directory = "C:\\Users\\" + get_user + "\\AppData\\Local\\BugWorldSave\\save.txt";
	string directory = "C:\\Users\\" + get_user + "\\AppData\\Local\\BugWorldSave";
	//////////////////////////////////////////////////////////

	// Convert directory string to a const
	//////////////////////////////////////////////////////////
	const char* convert_dir_to_string = directory.c_str();
	//////////////////////////////////////////////////////////

	// Create the directory
	//////////////////////////////////////////////////////////
	if (mkdir(convert_dir_to_string) == -1) {
		cerr << "Error: " << strerror(errno) << endl;
	}
	else {
		cout << "File created";
	}
	//////////////////////////////////////////////////////////

	// Call function to add to file
	//////////////////////////////////////////////////////////
	add_to_file(save_directory);
	//////////////////////////////////////////////////////////

	return;
}

void add_to_file(string directory) {

	//Save to file											
	//////////////////////////////////////////////////////////
	ofstream save_file;

	save_file.open(directory);


	save_file << "Writing to file..." << endl;
	save_file << "something" << endl;
	save_file << endl;



	save_file.close();
	//////////////////////////////////////////////////////////

	return;

}