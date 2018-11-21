#include "folder.h"

using namespace std;

// Folder class constructor, grabs files from the given address
Folder::Folder(const string& name, const string& address) : Storable(name, address) {

}

// Adds storable to folder
void Folder::append(Storable* newStorable) {
	this->storedContent.push_back(newStorable);
}

// Returns number of files and/or folders stored
size_type Folder::getStorageCount() {
	return this->_storedContent.size;
}

// Returns files as vector of files
vector<File> Folder::getStoredFiles() {
	return this->_storedContent;
}
