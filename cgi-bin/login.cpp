#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>

#include "loginServer.cpp"

using namespace std;
using namespace cgicc;

int main() {
	Cgicc formData;
	loginServer login;

	cout << "Content-type: text/html" << endl << endl;
	cout << "<html> \n";
	cout << "<head><title>Login</title></head>\n";
	cout << "<body>\n";

	form_iterator username = formData.getElement("username");
	form_iterator password = formData.getElement("password");

	cout << "<br>";

	if (login.checkPassword(**username, **password) == 1) {
		cout << "<br>";
		cout << "<a href='../addUser.html'>Add user</a>" << endl;
		cout << "<br>";
		cout << "<a href='../removeUser.html'>Remove user</a>" << endl;
		cout << "<br>";
		cout << "<a href='../upLoad.html'>Upload File</a>" << endl;
		cout << "<br>";
		cout << "<a href='../cgi-bin/download.cgi'>Download File</a>" << endl;
		cout << "<br>";
	} else if (login.checkPassword(**username,**password) == 2) {
		cout << "<br>";
		cout << "<a href='../upLoad.html'>Upload File</a>" << endl;
		cout << "<br>";
		cout << "<a href='../cgi-bin/download.cgi'>Download File</a>" << endl;
		cout << "<br>";
	}

	cout << "<br />\n";
	cout << "</body>\n";
	cout << "</html>\n";

	return 0;
}
