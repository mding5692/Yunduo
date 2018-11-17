#include <iostream>
#include <string>

class user{
	private:
		std::string username;
		std::string password;
		std::string permit;
	public:	
		user();
		~user();	
		std::string getUsername();
		void setUsername(std::string uname);
		std::string getPassword();
		void setPassword(std::string pwd);
		std::string getPermit();
		void setPermit(std::string pmt);
};


