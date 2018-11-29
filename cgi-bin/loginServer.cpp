/*	Author: Group 17
 *	This class includes all login related functions.
 *	
 *	Two types of users: admin and normal user are using this loginServer
 *	to check the password and permission when they are logging in to the system
 *
 * */
#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include "loginServer.h"
#include "admin.cpp"


using namespace std;

/*create the admin */
admin adminUser;

/* Use hash maps to store username and password data*/
unordered_map<string,string> userInfo;
/*Use hash maps to store username and userPermission*/
unordered_map<string,string> userPermission;

/*Current login text file storage location*/
string loginTextFile = "/var/www/html/login.txt";

/*Current permission text file storage location*/
string loginPermissionFile = "/var/www/html/permission.txt";

/* Constructor
 *
 *	Data of username, user password and user permission
 *	are read from the two text file and stored into
 *	the two hash maps for later usage.
 *
 * */
loginServer::loginServer(){
	ifstream readFile;
	ifstream readPermission;
	string line;
	string pmt;
	string separator = ",";
	/*read the login file and store the data into the userInfo map*/
	readFile.open(loginTextFile);
	readPermission.open(loginPermissionFile);
	if (readFile.is_open()) {
		while(!readFile.eof()){
			size_t pos = 0;
			getline(readFile,line);
			while((pos = line.find(separator)) != std::string::npos){
				string key = line.substr(0,pos);
				line.erase(0,pos + separator.length());
				userInfo[key] = line;
			}

		}		
		readFile.close();
	}

	/*read the permission file and store the data into the userPermission map*/
	if(readPermission.is_open()){	
		while(!readPermission.eof()){
			size_t position = 0;
			getline(readPermission,pmt);
			while((position = pmt.find(separator)) != string::npos){
				string key = pmt.substr(0,position);
				pmt.erase(0,position + separator.length());
				userPermission[key] = pmt;
			}
		}
		readPermission.close();
	}

	else if(!readFile.is_open() || !readPermission.is_open()){
		cout << "Unable to get login info from server";
	}
	
	
};

// Destructor
loginServer::~loginServer(){};

/*	method to check the user permission
 *
 *	if the username is not found, return the user was not given permission
 *	else return the permission detail
 *
 * */
string loginServer::checkPermission(string inputn){
	string permit = "";
	if(userPermission.find(inputn) == userPermission.end()){
		cout << "User was not given permission" << endl;
	}
	else{
		permit = userPermission[inputn];
	}
	return permit;
}


/*	method to check username and password
 *
 *	if username is not found, return the user does not exist
 *	else if the password does not match, return wrong password
 *	else if the password is correct, print the welcome message and check permission of the user
 *
 *	*/
int loginServer::checkPassword(std::string inputUName, std::string inputpw){
	//if user does not exist
	if (userInfo.find(inputUName) == userInfo.end()){
		std::cout << "User name does not exist.";
		return 3;
	}
	//if input password is wrong
	else if (userInfo[inputUName] != inputpw){
		cout << "Your password is incorrect. \n";
		return 4;

	}
	else if (userInfo[inputUName] == inputpw){
		cout << "Welcome back!" << endl;
		string pmt = checkPermission(inputUName);
		/*	check the permission of the user
		 *
		 *	if permission equals 5, it's the admin user.
		 *	if permission equals 1, user is allowed to upload and download files.
		 *	if permission equals 2, user is allowed to upload, download and remove files.
		 *	if permission equals 0, user is only allowed to download files.
		 *
		 * */
		if (pmt == "5" ){
			std::cout << inputUName << std::endl;
			return 5;
			
		} 
		else if (pmt == "1"){
			std::cout << inputUName <<std::endl ;
			return 1;	
		}
		else if (pmt == "2"){
			std::cout << inputUName << std::endl;
			return 2;
		}
		else if (pmt == "0"){
			cout << inputUName << endl;
			return 0;
		}

		

	}
	return 0;
			
}

//method for admin to add users
void loginServer::addUser(std::string name, std::string pw, std::string pmt){
	if (userInfo.find(name) == userInfo.end()) {
		userInfo[name] = pw;
		userPermission[name] = pmt;
		
		/*call the adduser function from admin class*/
		adminUser.adduser(name,pw,pmt);
		
		cout << "User added" << endl;
	} else {
		cout << "User already added before" << endl;
	}

}

//method for admin to remove users
void loginServer::removeUser(std::string name){
	if (userInfo.find(name) == userInfo.end()) {
		cout << "User doesn't exist." << endl;
	} 
	else {
		
		/*call the remove user function from admin class*/
		adminUser.removeuser(name);


		// Removes from unordered map
		userInfo.erase(name);
		userPermission.erase(name);
		cout << "User removed successfully" << endl;
	}

}
		


