#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>

using namespace std;
using namespace cgicc;

int main(){
  Cgicc formdata;
	
  cout << "Content-type: text/html" << endl << endl;
  cout << "<html> \n";
  cout << "<head><title>Remove files</title></head>\n";
  cout << "<body>\n";

  form_iterator path = formdata.getElement("path");
  
  string filePath = path->getValue();
  
  if( remove(filePath.c_str()) != 0 ){
    cout << "<p>file does not exist</p>";
  }
  else
    cout << "<p>file successfile deleted, refresh download page to see all the files on the cloud</p>";
  cout << "</body></html>";

  return 0;
}

