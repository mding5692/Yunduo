#include <iostream>
#include <unordered_map>
#include <string>
#include "user.cpp"

class loginServer{
	private:
		std::unordered_map<std::string, user*> userInfo;
		

	public:
		loginServer();
		~loginServer();
		int checkPassword(std::string inputUName, std::string inputpw);
		void addUser(std::string name, std::string pw, std::string pmt);
		void removeUser(std::string name);

	};

