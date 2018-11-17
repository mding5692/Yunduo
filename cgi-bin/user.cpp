#include <iostream>
#include <fstream>
#include <string>
#include "user.h"

using namespace std;

string name;
string password;
//permission details metioned below
string permit;

//constructor
user::user(){
	name = "";
	password = "";
	permit = "0";
}

//destructor
user::~user(){}

string user::getUsername(){
	return name;
}

//setter method for the username
void user::setUsername(string uname){
	name = uname;
}

//getter method for the password
string user::getPassword(){
	return password;
}

//setter method for the password
void user::setPassword(string pwd){
	password = pwd;
}

/*permission:
 * 0 -> download only (basic function)
 * 1 -> upload and download
 * 2 -> upload, download and remove file
 * 5 -> admin
 */

//getter method for permission
string user::getPermit(){
	return permit;
}

//setter method for permission
void user::setPermit(string pmt){
	permit = pmt;
}



