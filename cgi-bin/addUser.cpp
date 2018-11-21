#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

#include "loginServer.cpp"

using namespace std;
using namespace cgicc;

int main(){
	Cgicc formData;
	loginServer login;

	cout <<"Content-type:text/html\r\n\r\n";
	cout << "<html> \n";
	cout << "<head> \n";
	cout << "<title> User Added</title>\n";
	cout << "</head> \n";
	cout << "<body>\n";

	form_iterator username = formData.getElement("user_name");
	form_iterator password = formData.getElement("pass_word");
	form_iterator permission = formData.getElement("user_permit");

	login.addUser(**username, **password, **permission);

	cout << "</body>";
	cout << "</html>";
}

