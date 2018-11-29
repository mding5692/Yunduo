/* @Authors: CS 3307 Group 17
 * @brief: Remove user implementation
 * @detailed: We implement in our main function, code that can remove users based on username
 * If user exists, then user is deleted and success message appears
 * If we can't find user, then error message appears saying user not found
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>

#include "loginServer.cpp"

using namespace std;
using namespace cgicc;

int main() {
	// Uses both CGICC objects + loginServer class
	Cgicc formData;
	loginServer login;

	// Necessary code to display html using C++
	cout << "Content-type: text/html" << endl << endl;
	cout << "<html>";
	cout << "<head><title>Removing User</title></head>";
	cout << "<body>";

	// Grabs the username from the textbox with the name of removedUser
	// using CGICC object
	form_iterator username = formData.getElement("removedUser");

	// LoginServer removes users and gives either success or error message
	login.removeUser(**username);

	cout << "<br>";
	cout << "</body></html>";

	return 0;
}
