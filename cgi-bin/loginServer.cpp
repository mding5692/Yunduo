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
unordered_map<string,user*> userInfo;

// Current login storage location
string loginTextFile = "/var/www/html/login.txt";

// Constructor
loginServer::loginServer(){
	
	user u;
	ifstream readFile;
	string line;
	string separator = ",";
	readFile.open(loginTextFile);
	if (readFile.is_open()) {
		while (!readFile.eof()) {
		
			vector<string> v;
			getline(readFile,line);
			istringstream ss(line);
			string token;

			while(getline(ss,token,',')){
				v.push_back(token);
			}
			string key = v[0];
			u.setUsername(v[0]);
			u.setPassword(v[1]);
			u.setPermit(v[2]);
			userInfo[v[0]] = &u;
		}



/*
			size_t pos = 0;
			getline(readFile, line);
			while ((pos = line.find(separator)) != std::string::npos) {

				string key = line.substr(0, pos);
				line.erase(0, pos + separator.length());	

				userInfo[key] = line;
*/
			
		
		readFile.close();
	} else {
		cout << "Unable to get login info from server";
	}
};

// Destructor
loginServer::~loginServer(){};

// Checks username and password
int loginServer::checkPassword(std::string inputUName, std::string inputpw){

	//if user does not exist
	if (userInfo.find(inputUName) == userInfo.end()){
			std::cout << "User name does not exist. \n";
		return 3;
	}
	//if input password is wrong
	else if (userInfo[inputUName]->getPassword() != inputpw){
		std::cout << "Your password is incorrect. \n";
		return 4;

	}
	else if (userInfo[inputUName]->getPassword() == inputpw){
		std::cout << "Welcome back! \n" << std::endl;
		//check if the user is admin or normal user
		if (userInfo[inputUName]->getPermit() == "5" ){
			std::cout << inputUName << std::endl;
			return 1;
			
		} else {
			std::cout << inputUName <<std::endl ;
			return 2;	
		}
	}
	return 0;
			
}

//method for admin to add users
void loginServer::addUser(std::string name, std::string pw, std::string pmt){
	if (userInfo.find(name) == userInfo.end()) {
		// Adds to unordered map
		user newUser;
		newUser.setUsername(name);
		newUser.setPassword(pw);
		newUser.setPermit(pmt);
		userInfo[name] = &newUser;

		// Adds to text file storing user credentials
		ofstream outputFile;
		outputFile.open(loginTextFile, ios::out | ios::app);
		outputFile << name << "," << pw << "," << pmt << endl;

		cout << "User added" << endl;
	} else {
		cout << "User already added before" << endl;
	}

}

//method for admin to remove users
void loginServer::removeUser(std::string name){
	if (userInfo.find(name) == userInfo.end()) {
		cout << "User doesn't exist." << endl;
	} else {
		
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

		// Removes from unordered map
		userInfo.erase(name);
		cout << "User removed successfully" << endl;
	}

}
		


