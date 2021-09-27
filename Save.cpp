#include <iostream>
#include <fstream>

void save() {
	char letter = "a";
	ofstream out("C:\\Users\\Adr\\source\\repos\\BugWorld\\Save Files", ofstream::app);

	out << letter << endl;
	out.close();
}