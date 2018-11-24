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

#include "./Controllers/fileServer.cpp"

using namespace std;
using namespace cgicc;

int main() {

	Cgicc cgi;
	FileServer fileServer;

	//html interface to interact with the user
	cout << "Count-type:text/html\r\n\r\n";
	cout << "<html>\n";
	cout << "<head>\n";
	cout << "<title> File Upload in CGI</title>\n";
	cout << "</head>\n";
	cout << "<body>\n";
	
	//get the uploaded file and store it into 'file'
	const_file_iterator file = cgi.getFile("userfile");
	fileServer.uploadFile(file);
	
	// if (file != cgi.getFiles().end()) {

	// 	//store the name of the file into 'filename'
	// 	string filename = file->getFilename();
	// 	string fullFilename = "/var/www/html/saveFile/" + filename;		
	// 	//create output file 'outfile'
	// 	ofstream outfile;
	// 	outfile.open(fullFilename.c_str());
	// 	//display data of the uploaded file
	// 	outfile  << file->getData() << endl;
	// 	outfile.close();
	// 	//print success line
	// 	cout << "\n" << filename << " uploaded successfully";
	// } else { // Prints fail if cannot upload
	// 	cout << "File not uploaded successfully" << endl;
	// 	cout << "<a href='../upLoad.html'> try again </a>" << endl;
	// }
	cout <<	"</body>\n";
	cout << "</html>\n";
	return 0;
}

