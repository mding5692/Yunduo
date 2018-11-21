#ifndef FOLDER_H
#define FOLDER_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include <iomanip>

#include "storable.h"
#include "file.cpp"

class Folder : public Storable {
	public:
		Folder(const std::string& name, std::string& address);
		void append(Storable* newStorable);
		size_type getStorageCount();
		std::vector<Storable*> getStoredFiles();
	private:
		std::vector<Storable*> _storedContent;
};

#endif

