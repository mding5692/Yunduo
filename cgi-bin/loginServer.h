#include <iostream>
#include <unordered_map>
#include <string>

class loginServer{
	private:
		std::unordered_map<std::string, std::string> userInfo;
		

	public:
		loginServer();
		~loginServer();
		int checkPassword(std::string inputUName, std::string inputpw);
		void addUser(std::string name, std::string pw);
		void removeUser(std::string name);

	};

