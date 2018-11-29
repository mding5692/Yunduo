/***********************************************************
* @author: CS 3307 Group 17
* @brief: Processes new user info and adds a new user
* @detailed: This file is for the addUser function. 
* Enter input in the textboxes with names "user name", "password", and
*"user permit" to create the new user and then press the submit button.
* If user doesnt exist yet, creates new user and sets their permission level
* If user already exists, then shows an error message
*
*Parameters are username, password, permission.
*Save the input of the parameters and store as the new user.
*
*/
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
	// Declares loginServer + Cgicc objects
	// Enables our code to access html input
	// and add a user
	Cgicc formData;
	loginServer login;
	
	// Necessary starting code to print out html
	cout <<"Content-type:text/html\r\n\r\n";
	cout << "<html> \n";
	cout << "<head> \n";
	cout << "<title> User Added</title>\n";
	cout << "</head> \n";
	cout << "<body>\n";

	/*take input from webpage*/
	form_iterator username = formData.getElement("user_name");
	form_iterator password = formData.getElement("pass_word");
	form_iterator permission = formData.getElement("user_permit");

	/*call the addUser function from the loginServer*/
	/*take the parameters "username", "password", "permission"
	 as the input of the method addUser() to create the new user */
	login.addUser(**username, **password, **permission);

	cout << "</body>";
	cout << "</html>";
}

