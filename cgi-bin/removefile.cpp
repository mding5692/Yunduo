
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>

using namespace std;
using namespace cgicc;

int main(){
  Cgicc formdata;
/// html header for remove file	
  cout << "Content-type: text/html" << endl << endl;
  cout << "<html> \n";
  cout << "<head><title>Remove files</title></head>\n";
  cout << "<body>\n";

/// grab the path using form data
  form_iterator path = formdata.getElement("path");
  
/// translate the path into string 
  string filePath = path->getValue();
  
/// This is the remove function that will remove the file if the filepath point to some file in the raspberry pi 
  if( remove(filePath.c_str()) != 0 ){
    cout << "<p>file does not exist</p>"; ///error message if file is not found
  }
  else
    cout << "<p>file successfile deleted, refresh download page to see all the files on the cloud</p>"; ///print a message if file is found and deleted 
  cout << "</body></html>";

  return 0;
}

