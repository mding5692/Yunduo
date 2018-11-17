#include <iostream>
#include <fstream>
//include <filesystem>
#include "admin.h"

using namespace std;

//constructor
admin::admin(){
	//create a file to store user names and password
	std::ofstream outfile ("login.txt");
	//give permissions
	//fs::permissions("login.txt",fs::perms::owner_all | fs::perms::group_all,fs::perm_options::add);
	//add admin user to the file
	outfile << "admin,abcdef" << endl;
	outfile.close();
};
