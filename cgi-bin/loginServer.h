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

