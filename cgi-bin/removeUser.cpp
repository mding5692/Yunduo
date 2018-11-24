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
	cout << "<html>";
	cout << "<head><title>Removing User</title></head>";
	cout << "<body>";

	form_iterator username = formData.getElement("removedUser");

	login.removeUser(**username);

	cout << "<br>";
	cout << "</body></html>";

	return 0;
}
