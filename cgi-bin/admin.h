#ifndef ADMIN_H
#define ADMIN_H

/*
 *	@Author: CS 3307Group 17
 *	@brief: Admin class for all admin functions
 *	@detailed: admin user can call the functions to add and remove users
 *	and set permission for users
 *
 * */

#include <iostream>
#include <fstream>
#include <string>

class admin{
	private:
		std::string username;
		std::string password;
		std::string permission;
	public:
		admin(std::string u,std::string pw, std::string pmt);
		admin();
		~admin();
		void adduser(std::string name,std::string pw, std::string pmt);
		void removeuser(std::string name);
		
};

#endif
