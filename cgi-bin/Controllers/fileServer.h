#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <sys/stat.h>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

#include "../Models/storable.h"
#include "../Models/file.cpp"
#include "../Models/folder.cpp"

class FileServer {
	public:
		FileServer();
		~FileServer();
		void openDir(std::string dirName, std::string address);
		void createDir(std::string dirName, std::string address);
		void removeFile(std::string fileAddress);
		void removeDir(std::string dirAddress);
		void uploadFile(cgicc::const_file_iterator file);
		void loadFilesForDownload();
	private:
		Storable* _root;

		// Stores files already opened so can open them
		// And can display one overall opened file tree UI
		std::unordered_map<std::string, std::string> _alreadyOpenedFolderNames;
};
