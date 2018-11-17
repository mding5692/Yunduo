#include "file.h"

using namespace std;

// File class constructor
File::File(string filename, string filetype, string fileAddress) {
	fname = filename;
	ftype = filetype;
	faddr = fileAddress;
}

// File class destructor
File::~File() {

}

// Returns file info in string format
string File::to_string() {
	string result = "Filename: " + fname + ", file type: " + ftype + ", address: " + faddr;
	return result;	
}

// Returns filename as string
string File::getFilename() {
	return fname;
}

// Returns filetype as string
string File::getFiletype() {
	return ftype;
}

// Returns file address as string 
string File::getAddress() {
	return faddr;
}

