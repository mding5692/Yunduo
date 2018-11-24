#include "fileServer.h"

using namespace std;
using namespace cgicc;

// Constants
const string FOLDER_ROOT_ADDR = "/var/www/html/saveFile/";
const string CREATING_FOLDER = "creating_folder";
const string ALREADY_CREATED = "already_created_folder";
const string OPENED_FOLDERS = "/var/www/html/folder.txt";

// FileServer class constructor
FileServer::FileServer()
{
	// Initializes root directory
	string rootName = "";
	this->_root = new Folder(rootName, FOLDER_ROOT_ADDR);
	// Opens the directories that already have been previously opened
	// in this session
	// this->_alreadyOpenedFolderNames = openedFolders;

	// System variables
	DIR *dir;
	struct dirent *ent;
	struct stat s;

	if ((dir = opendir(FOLDER_ROOT_ADDR.c_str())) != NULL) {
		while ((ent = readdir(dir)) != NULL)
		{
			string fileName = string(ent->d_name);

			if (fileName.compare(".") == 0 || fileName.compare("..") == 0)
			{
				continue;
			}

			string filePath = FOLDER_ROOT_ADDR + fileName;
			if (stat(filePath.c_str(), &s) == 0)
			{

				if (s.st_mode & S_IFDIR)
				{
					//it's a directory
					Storable* newFolder = new Folder(fileName, filePath);
					this->_root->append(newFolder);
					cout << newFolder->getName() << endl;
				}
				else if (s.st_mode & S_IFREG)
				{
					//it's a file
					Storable* newFile = new File(fileName, filePath);
					this->_root->append(newFile);
					cout << newFile->getName() << endl;
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
FileServer::~FileServer(){}

void FileServer::openDir(string dirName, string address) {
	
}

void FileServer::createDir(string dirName, string address) {

}

void FileServer::removeFile(string fileAddress) {

}

void FileServer::removeDir(string dirAddress) {

}

// TODO: Needs an address as parameter
void FileServer::uploadFile(const_file_iterator file) {
	Cgicc cgi;

	if (file != cgi.getFiles().end()) {
		//store the name of the file into 'filename'
		string filename = file->getFilename();
		string fullFilename = "/var/www/html/saveFile/" + filename;		
		//create output file 'outfile'
		ofstream outfile;
		outfile.open(fullFilename.c_str());
		//display data of the uploaded file
		outfile  << file->getData() << endl;
		outfile.close();
		//print success line
		cout << "\n" << filename << " uploaded successfully";
	} else { // Prints fail if cannot upload
		cout << "File not uploaded successfully" << endl;
		cout << "<a href='../upLoad.html'> try again </a>" << endl;
	}
}

void FileServer::loadFilesForDownload() {

}
