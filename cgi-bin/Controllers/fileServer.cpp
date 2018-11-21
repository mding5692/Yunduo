#include <unordered_map>
#include <sys/stat.h>
#include "../Models/folder.cpp"
#include "fileServer.h"

using namespace std;

// Constants
const string FOLDER_ROOT_ADDR = "/var/www/html/saveFile/";
const string CREATING_FOLDER = "creating_folder";
const string ALREADY_CREATED = "already_created_folder";

// FileServer class constructor
FileServer::FileServer()
{

	// System variables
	DIR *dir;
	struct dirent *ent;
	struct stat s;

	if ((dir = opendir(FOLDER_ROOT_ADDR)) != NULL {
		while ((ent = readdir(dir)) != NULL)
		{
			string fileName = string(ent->d_name);

			if (fileName.compare(".") == 0 || fileName.compare("..") == 0)
			{
				continue;
			}

			string filePath = FOLDER_ROOT_ADDR + fileName;
			if (stat(filePath, &s) == 0)
			{

				if (s.st_mode & S_IFDIR)
				{
					//it's a directory
					
					folders.push_back(newFolder);
				}
				else if (s.st_mode & S_IFREG)
				{
					//it's a file
					File newFile = File(fileName, filePath);
					files.push_back(newFile);
				}
				else
				{
					continue;
				}
			}
			else
			{
				continue;
			}
		}
		
	} else {
		cout << "Unable to open your cloud folders, try again!" << endl;
	}
}

// FileServer destructor
FileServer::~FileServer()
{
}
