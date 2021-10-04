#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"
#include "Tile.h"
#include "Entity.h"



using namespace std;

int main() 
{
    string get_name = getenv("USERNAME");
    // Change directory 
    string directory = "C:\\Users\\" + get_name + "\\Documents\\CS 370\\SaveFile\\save.txt";

    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = 1 + 2;
    }

    for (int i = 0; i < 10; i++) {
        cout << "arr pos " << i << " value: " << arr[i] << endl;
    }

    ofstream Save_File;
    Save_File.open(directory);

    Save_File << "Writing to file...." << endl;

    for (int i = 0; i < 10; i++) {
        Save_File << "arr pos " << i << " value: " << arr[i] << endl;
    }



    return 0;
}}