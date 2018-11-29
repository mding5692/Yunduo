#ifndef LOGIN_SERVER_H
#define LOGIN_SERVER_H

/*	Author: Group 17
 *	@brief: This class includes all login related functions.
 *	
 *	@Detailed: Two types of users: admin and normal user are using this loginServer
 *	to check the password and permission when they are logging in to the system
 *
 * */

#include <iostream>
#include <unordered_map>
#include <string>


class loginServer{
	private:
		std::unordered_map<std::string, std::string> userInfo;
		std::unordered_map<std::string, std::string> userPermission;
		

	public:
		loginServer();
		~loginServer();
		std::string checkPermission(std::string inputn);
		int checkPassword(std::string inputUName, std::string inputpw);
		void addUser(std::string name, std::string pw,std::string pmt);
		void removeUser(std::string name);

	};

#endif
