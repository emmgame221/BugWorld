#include "Game.h"
#include <iostream>
#include <fstream>
#include <direct.h>
#include <string>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

#pragma warning(disable: 4996)


void save()

{
    // Get user info
    /********************************************************************************************************/
    // Initialize Variables to get user info
    std::string getUser;
    std::string saveDirectory;
    std::string directory;

    // Get user info
    getUser = getenv("USERNAME");
    saveDirectory = "C:\\Users\\" + getUser + "\\AppData\\Local\\BugWorldSave\\Bug_World_Save_Archive.xml";
    directory = "C:\\Users\\" + getUser + "\\AppData\\Local\\BugWorldSave";
    /********************************************************************************************************/

    // Create Directory
    /********************************************************************************************************/

    const char* convertDirectoryToString = directory.c_str();

    if (mkdir(convertDirectoryToString) == -1)
        std::cerr << "Erro: " << std::strerror(errno) << std::endl;
    else
        std::cout << "File created" << std::endl;
    /********************************************************************************************************/

    /*filename to work with*/
    std::string filename = saveDirectory;

    /*create an ofstream object for writing to file*/
    std::ofstream out(filename);
    
    /*create a xml_oarchive object to archive an array to a xml file*/
    boost::archive::xml_oarchive xml_output_archive(out);

    /*create an object of class*/
    Game object1(3, 3, 1);

    /*archive a class object using & */
    xml_output_archive& BOOST_SERIALIZATION_NVP(object1);

    /*display the content of archived object to console*/
    std::cout << "Archived to " << filename << std::endl;
    //object1.print();

    /*disconnect the file*/
    out.close();



    return;
}

void load()
{
    std::string getUser;
    std::string saveDirectory;
    std::string directory;
    getUser = getenv("USERNAME");
    saveDirectory = "C:\\Users\\" + getUser + "\\AppData\\Local\\BugWorldSave\\Bug_World_Save_Archive.xml";
    directory = "C:\\Users\\" + getUser + "\\AppData\\Local\\BugWorldSave";
    std::string filename = saveDirectory;

    /*create an ifstream object for reading from file*/
    std::ifstream in(filename);

    /*create a xml_iarchive object to restore the archieved content*/
    boost::archive::xml_iarchive xml_input_archive(in);

    /*create an object to store the restored data*/
    Game object2;

    /*restore the archived content using &*/
    xml_input_archive& BOOST_SERIALIZATION_NVP(object2);

    /*disconnect the file*/
    in.close();

    /*display the restored content to console*/
    std::cout << "Restored archived content from " << filename << " : " << std::endl;
    
    return;
}
