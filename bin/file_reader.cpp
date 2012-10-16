//FILE_READER.CPP

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include "headers/globals.h"
#include "headers/file_reader.h" // class's header file

using namespace std;

int *row;
// class constructor
FileReader::FileReader(const char *filename) {
	ifstream fstr(filename);
	string str;

	//Read first line
	getline(fstr, str);
	MAP_HEIGHT = atoi(str.substr(8, str.size() - 8).c_str());

	//Read second line
	getline(fstr, str);
	MAP_WIDTH = atoi(str.substr(7, str.size() - 7).c_str());

	//Init pointer array
	try {
		row = new int[MAP_WIDTH];
		map = new int*[MAP_HEIGHT];
		for(int i = 0; i < MAP_HEIGHT; i++) {
			map[i] = new int[MAP_WIDTH];
		}
	} catch(exception &e) {
		cout << "Standard Error: " << e.what() << endl;
		system("pause");
	}

	//Read subsequent lines
	for(int i = 0; i < MAP_HEIGHT; i++) {
		getline(fstr, str);
		for(int j = 0; j < MAP_WIDTH; j++) {
			row[j] = atoi(str.substr(j, 1).c_str());
		}
		for(int j = 0; j < MAP_WIDTH; j++) {
			map[i][j] = row[j];
		}
	}
	fstr.close();
	delete[] row;
}

// class destructor
FileReader::~FileReader() {
	for(int i = 0; i > MAP_HEIGHT; i++) {
		delete[] map[i];
	}
	delete[] *map;
}
