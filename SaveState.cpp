#include <direct.h>
#include <string>
#include <fstream>
#include <iostream>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include "Game.h"

#pragma warning(disable: 4996)

void getUserInfo(std::string& getUser, std::string& saveDirectory, std::string& directory);
void createDirectory(std::string& getUser, std::string& saveDirectory, std::string& directory);


void save()
{
    std::string getUser;
    std::string saveDirectory;
    std::string directory;

    getUserInfo(getUser, saveDirectory, directory);
    createDirectory(getUser, saveDirectory, directory);

    /*filename to work with*/
    std::string filename = saveDirectory;

    /*create an ofstream object for writing to file*/
    std::ofstream out(filename);

    /*create a xml_oarchive object to archive an array to a xml file*/
    boost::archive::xml_oarchive xml_output_archive(out);

    /*create an object of class*/
    Game object1(3, 3, 2);

    /*archive a class object using & */
    xml_output_archive& BOOST_SERIALIZATION_NVP(object1);

    /*display the content of archived object to console*/
    std::cout << "Archived to " << filename << std::endl;
    //object1.print();

    /*disconnect the file*/
    out.close();

    //displayContents(filename);



    /*return 0 to caller*/
    return;

}

void getUserInfo(std::string& getUser, std::string& saveDirectory, std::string& directory)
{
	getUser = getenv("USERNAME");
	saveDirectory = "C:\\Users\\" + getUser + "\\AppData\\Local\\BugWorldSave\\Bug_World_Save_Archive.xml";
	directory = "C:\\Users\\" + getUser + "\\AppData\\Local\\BugWorldSave";

	return;
}

void createDirectory(std::string& getUser, std::string& saveDirectory, std::string& directory)
{
	const char* convertDirectoryToString = directory.c_str();

	if (mkdir(convertDirectoryToString) == -1)
		std::cerr << "Erro: " << std::strerror(errno) << std::endl;
	else
		std::cout << "File created" << std::endl;

	return;

}