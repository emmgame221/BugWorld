#include <iostream>
#include <fstream>
#include "Game.h"
#include "Tile.h"
#include "Entity.h"



using namespace std;

int main() {
    // initialized data to be saved to the file
    char letter = 'a';
    int num = 1;
    double dec = 2.0;
    int arr[10];

    // for loop to fill the array
    for (int i = 0; i < 10; i++) {
        arr[i] = 1 + 2;
    }

    // display the contents of the array
    for (int j = 0; j < 10; j++) {
        cout << "arr pos" << j << " Value: " << arr[j] << endl;
    }
    // declare file name
    ofstream Save_File;

    // opening the file and stating where it will be saved and what type of file it is
    Save_File.open("C:\\Users\\Adr\\Documents\\CS 370\\SaveFile\\Save.txt");

    // information saved to the file
    Save_File << "Writing this to a file.\n";
    Save_File << letter << endl;
    Save_File << num << endl;
    Save_File << dec << endl;

    // for loop to display the contents of the array in the file
    for (int j = 0; j < 10; j++) {
        Save_File << "arra pos " << j << " Value: " << arr[j] << endl;

    }

    // close the file
    Save_File.close();
    return 0;


}}