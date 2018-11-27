/* @authors: CS 3307 Group 17
 * @brief: For those users without permission to delete files, they see this download page without remove file functionality
 * @detailed: This page enables users to download files, it opens up the saveFile directory and prints out the files stored on there
 * if the directory can't be opened, it prints an error message: Unable to open directory
 * The links are pressable on html and when pressed enable user to download a file
 * The main function generates an html page with the download links
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <dirent.h>

using namespace std;

int main() {
	// System variables used to access directory
	DIR *dir;
	struct dirent *ent;

	// Necessary html + C++ code written to show that an html page will be outputted
	cout << "Content-type: text/html" << endl << endl;
	cout << "<html> \n";
	cout << "<head><title>Download files and Remove files</title></head>\n";
	cout << "<body>\n";

	// Description of what to do for the user
	cout << "<p><b>Below are the files currently in your directory</b></p>";
	cout << "<p> Download files by pressing on them</p>";
        cout<< "<META HTTP-EQUIV='refresh' CONTENT='10'>";

	// Opens up the saveFile directory where files can be uploaded
	if ((dir = opendir("/var/www/html/saveFile")) != NULL) {
		// Iterates over all the files in saveFile directory
		while ((ent = readdir(dir)) != NULL) {

			string dirName = string(ent->d_name);
			// ignores . or current directory and .. or parent directory
			if (dirName.compare(".") == 0 || dirName.compare("..") == 0) {
				continue;
			}
			
			// Displays each file as a download html link
			// If user presses on the link, the file will be downloaded to user's computer
			cout << "<br>";
			string fileName  = "..//saveFile/" + dirName;
			string fullfileName = "/var/www/html/saveFile/" + dirName;
			cout << "<a href=' " << fileName.c_str() << "'" <<  " download='download'>" << ent->d_name << "</a>" << endl;
			cout << "<br>";
		
		}
		// Closes directory when done
		closedir(dir);
	} else { // If can't open directory, shows error message instead	
		cout << "Unable to open directory" << endl;
	}

	// Ends html page
	cout << "</body></html>";

	return 0;
}

