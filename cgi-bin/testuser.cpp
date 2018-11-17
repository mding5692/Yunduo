#include <string>
#include <iostream>
#include "user.cpp"

int main(){
	user user;
	user.setUsername("a");
	user.setPassword("b");
	user.setPermit(3);
	cout << user.getUsername() << "\n" << user.getPassword() << "\n" << user.getPermit() << "\n" << endl;
}
