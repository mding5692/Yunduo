#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include "loginServer.h"
//include "admin.cpp"
//include "user.cpp"


using namespace std;

//call constructor to create admin user
//admin admin;
// Used to store username and password data
unordered_map<string,string> userInfo;
unordered_map<string,string> userPermission;

// Current login storage location
string loginTextFile = "/var/www/html/login.txt";

string loginPermissionFile = "/var/www/html/permission.txt";

// Constructor
loginServer::loginServer(){
	ifstream readFile;
	ifstream readPermission;
	string line;
	string pmt;
	string separator = ",";
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


// Checks username and password
int loginServer::checkPassword(std::string inputUName, std::string inputpw){
	//if user does not exist
	if (userInfo.find(inputUName) == userInfo.end()){
		std::cout << "User name does not exist.";
		return 3;
	}
	//if input password is wrong
	else if (userInfo[inputUName] != inputpw){
		//cout << userInfo[inputUName]->getPassword();
		cout << "Your password is incorrect. \n";
		return 4;

	}
	//else cout << "good" << endl;
	else if (userInfo[inputUName] == inputpw){
		cout << "Welcome back!" << endl;
		string pmt = checkPermission(inputUName);
		//check if the user is admin or normal user
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
		// Adds to unordered map
		//user newUser(name,pw,pmt);
		//newUser.setUsername(name);
	//	newUser.setPassword(pw);
	//	newUser.setPermit(pmt);
		userInfo[name] = pw;
		userPermission[name] = pmt;
		
		// Adds to text file storing user credentials
		ofstream outputFile;
		ofstream outputPermission;
		outputFile.open(loginTextFile, ios::out | ios::app);
		outputFile << name << "," << pw << endl;
		outputPermission.open(loginPermissionFile,ios::out | ios::app);
		outputPermission << name << "," << pmt << endl;
		
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
		
		// Deleting from text file holding user credentials
		string line;
		ifstream fin;

		fin.open(loginTextFile);
		ofstream temp;
		temp.open("/var/www/html/temp.txt");

		// Only saves lines of the text file that don't match the name we're deleting
		while (getline(fin, line)) {
			if (line.find(name) == string::npos) {
				temp << line << endl;
			}
		}

		temp.close();
		fin.close();
		
		// Renames temp text as actual login file
		remove("/var/www/html/login.txt");
		system("chmod 777 /var/www/html/temp.txt");
		rename("/var/www/html/temp.txt", "/var/www/html/login.txt");

		//Deleting from text file holding user permissions
		string pmt;
		ifstream pfin;

		pfin.open(loginPermissionFile);
		ofstream tempPermission;
		tempPermission.open("/var/www/html/tempPermission.txt");

		//Only saves lines of the text file that don't match the name we're deleting
		while (getline(pfin, pmt)){
			if (pmt.find(name) == string::npos){
				tempPermission << pmt << endl;
			}
		}
		tempPermission.close();
		pfin.close();
		
		//reames tempPermission text as actual permission file
		remove("/var/www/html/permission.txt");
		system("chmod 777 /var/www/html/tempPermission.txt");
		rename("/var/www/html/tempPermission.txt", "/var/www/html/permission.txt");

		// Removes from unordered map
		userInfo.erase(name);
		userPermission.erase(name);
		cout << "User removed successfully" << endl;
	}

}
		


