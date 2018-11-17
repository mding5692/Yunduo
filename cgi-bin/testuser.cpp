#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include "user.cpp"

int main(){
	user u;
	unordered_map<std::string,user*> test;
	//user.setUsername("a");
	//user.setPassword("b");
	//user.setPermit(3);
	vector<std::string> v;
	v.push_back("a");
	v.push_back("b");
	v.push_back("1");
	u.setUsername(v[0]);
	u.setPassword(v[1]);
	u.setPermit(v[2]);
	std::string a = "abc";
	test[v[0]] = &u;

	//cout << user.getUsername() << "\n" << user.getPassword() << "\n" << user.getPermit() << "\n" << endl;
	user* b;
	b = test["abc"];
	cout << b->getUsername();
	
}
