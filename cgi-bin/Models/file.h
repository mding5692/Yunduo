#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <dirent.h>


class File {
	public:
		File(std::string filename, std::string filetype, std::string fileAddress);
		~File();
		std::string to_string();
		std::string getFilename();
		std::string getFiletype();
		std::string getAddress();
	private:
		std::string fname;
		std::string ftype;
		std::string faddr;
};

#endif


