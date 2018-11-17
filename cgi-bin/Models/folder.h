#ifndef FOLDER_H
#define FOLDER_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>

#include "file.cpp"

class Folder {
	public:
		Folder(std::string foldername, std::string folderAddr, std::string state);
		~Folder();
		std::string to_string();
		std::string getFoldername();
		std::string getFolderAddress();
		std::string getFolderState();
		size_type getFileCount();
		std::vector<File> getFiles();
	private:
		std::string folderName;
		std::string folderAddress;
		std::string fState;
		std::vector<File> files;
};

#endif

