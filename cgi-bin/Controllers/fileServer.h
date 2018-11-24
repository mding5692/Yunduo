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

#include "../Models/storable.h"
#include "../Models/folder.cpp"

class FileServer {
	public:
		FileServer();
		~FileServer();
		void openDir(std::string dirName);
		void removeFile(std::string fileName);
		void removeDir(std::string dirName);
		bool uploadFile(cgicc::const_file_iterator);
		bool loadFilesForDownload();
	private:
		Storable* _root;

		// Stores files already opened so can open them
		// And can display one overall opened file tree UI
		std::unordered_map<std::string, std::string> alreadyOpenedFolderNames;
};
