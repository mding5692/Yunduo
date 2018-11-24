#include "folder.h"

using namespace std;

// Folder class constructor, grabs files from the given address
Folder::Folder(const string& name, const string& address) : Storable(name, address) {

}

// Adds storable to folder
void Folder::append(Storable* newStorable) {
	this->_storedContent.push_back(newStorable);
}

// Returns files as vector of files
vector<File> Folder::getStoredFiles() {
	return this->_storedContent;
}
