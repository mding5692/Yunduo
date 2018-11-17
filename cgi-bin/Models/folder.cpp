#include "folder.h"

using namespace std;

// Constants
const string FOLDER_ROOT_ADDR = "/var/www/html/saveFile/";
const string CREATING_FOLDER = "creating_folder";
const string ALREADY_CREATED = "already_created_folder";

// Folder class constructor, grabs files from the given address
Folder::Folder(string foldername, string folderAddr, string state) {
	// Sets class properties
	folderName = foldername;
	folderAddress = folderAddr;
	fState = state;

	// Sets variables for reading folder
	DIR *dir;
	struct dirent *ent;	

	// For when the folder is already created
	// and we want to access it
	if (state != CREATING_FOLDER) {
		string absFolderAddr = FOLDER_ROOT_ADDR + folderAddr;

		if ((dir = opendir(absFolderAddr)) != NULL) {
			while ((ent = readdir(dir)) != NULL) {
				
			}
		}
	}
}

// Folder destructor
Folder::~Folder() {

}

// Returns Folder class as string format
string Folder::to_string() {
	string result = "Foldername: " + folderName + ", folder address: ", + folderAddress;
	return result;
}

// Returns folder name as string
string Folder::getFoldername() {
	return folderName;
}

// Returns folder address as string
string Folder::getFolderAddress() {
	return folderAddress;
}

// Returns folder state as string
string Folder::getFolderState() {
	return fState;
};

// Returns num of files in folder as size_type
size_type Folder::getFileCount() {
	return files.size();
}

// Returns files as vector of files
vector<File> Folder::getFiles() {
	return files;
}

