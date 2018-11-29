/*
 *	Author: Gourp 17
 *	Admin class for all admin functions
 *	admin user can call the functions to add and remove users
 *	and set permission for users
 *
 *
 * */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "admin.h"

using namespace std;

/*attributes*/
string username;
string password;
string permission;

/*constructor with attributes*/
admin::admin(string u, string pw, string pmt){
	this->username = u;
	this->password = pw;
	this->permission = pmt;
}

/*constructor*/
admin::admin(){
	string username;
	string password;
	string permission;
}

/*destructor*/
admin::~admin(){}

/*	Function to add user.
 *	
 *	This function will be called from the loginServer.
 *	This function will open both the login file and the permission file
 *	and add in the username, password and permission respectively.
 *
 *
 * */
void admin::adduser(string name, string pw, string pmt){
	ofstream outputFile;
	ofstream outputPermission;
	outputFile.open("/var/www/html/login.txt",ios::out | ios::app);
	outputFile << name << "," << pw << endl;
	outputPermission.open("/var/www/html/permission.txt", ios::out | ios::app);
	outputPermission << name << "," << pmt << endl;
}

/*
 *	Funtion to remove user.
 *
 *	This function will be called from the loginServer.
 *	This function will remove the permission detail and login detail from both files.
 *
 *
 * */
void admin::removeuser(string name){
	string line;
	ifstream fin;

	fin.open("/var/www/html/login.txt");
	ofstream temp;
	temp.open("/var/www/html/temp.txt");

	/*Only save s lines of the text file that don't match the name we're deleting*/
	while (getline(fin,line)){
		if (line.find(name) == string::npos){
			temp << line << endl;
		}
	}

	temp.close();
	fin.close();

	/* Renames temp text as actual login file*/
	remove("/var/www/html/login.txt");
	system("chmod 777 /var/www/html/temp.txt");
	rename("/var/www/html/temp.txt","/var/www/html/login.txt");

	/*Deleting from text file holding user permissions*/
	string pmt;
	ifstream pfin;

	pfin.open("/var/www/html/permission.txt");
	ofstream tempPermission;
	tempPermission.open("/var/www/html/tempPermission.txt");

	/*Only saves lines of the text file that don't match the name we are deleting*/
	while (getline(pfin,pmt)){
		if (pmt.find(name) == string::npos){
			tempPermission << pmt << endl;
		}
	}	
	tempPermission.close();
	pfin.close();

	/*rename tempPermission text as actual permission file*/	
	remove("/var/www/html/permission.txt");
	system("chmod 777 /var/www/html/tempPermission.txt");
	rename("/var/www/html/tempPermission.txt","/var/www/html/permission.txt");

}







