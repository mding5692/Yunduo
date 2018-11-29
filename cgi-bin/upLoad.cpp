/*
 * @author CS3307-group17
 * @brief:this class is used to user to upload his files such as media files, content files.
 * @detail:the header and footer is desgined by html which is used to interact with the user
 * when user clink the file button,the file instance will open the directory of file for users
 * then users choose the file which he want to upload. then this file will be saved into 
 * saveFile folder and print a message to user for upload successfully or not
 * */

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

using namespace std;
using namespace cgicc;

int main() {
	// CGICC class object declared to use form input
	Cgicc cgi;
	//html interface to interact with the user
	cout << "Count-type:text/html\r\n\r\n";
	cout << "<html>\n";
	cout << "<head>\n";
	cout << "<title> File Upload in CGI</title>\n";
	cout << "</head>\n";
	cout << "<body>\n";
	
	//get the uploaded file and store it into 'file'
	const_file_iterator file = cgi.getFile("userfile");
	
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
	cout <<	"</body>\n";
	cout << "</html>\n";
	return 0;
}

