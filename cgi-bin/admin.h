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
