//FILE_READER.H

#ifndef FILEREADER_H
#define FILEREADER_H

#include "globals.h"

class FileReader {
	public:
		// class constructor
		FileReader(const char *filename);

		// class destructor
		~FileReader();

		//Map of integers
		int **map;
};

#endif // FILEREADER_H
