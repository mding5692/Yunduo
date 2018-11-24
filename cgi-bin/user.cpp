#include <iostream>
#include <fstream>
#include <string>
#include "user.h"

using namespace std;

string username;
string password;
//permission details metioned below
string permit;

//constructor
user::user(){}

//parameter constructor
user::user(string uname,string pwd, string pmt){
	this->username = uname;
	this->password = pwd;
	this->permit = pmt;
}

//destructor
user::~user(){}

bool user::operator== (const user& rhs){
	return (username == rhs.username);
	}

bool user::operator!= (const user& rhs){
	return (username != rhs.username);
}

string user::getUsername(){
	return username;
}

//setter method for the username
void user::setUsername(string uname){
	this->username = uname;
}

//getter method for the password
string user::getPassword(){
	return password;
}

//setter method for the password
void user::setPassword(string pwd){
	this->password = pwd;
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
	this->permit = pmt;
}



