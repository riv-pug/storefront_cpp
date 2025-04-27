#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
using namespace std;

class User
{

protected:
	string username;
	string password;
	string usertype;
	
public:
	User();
	User(string, string, string );
	
	virtual void login() {
		cout << "Logging in:  " << username << endl;
	}

	virtual void logout() {
	
		cout << "Logging out: " << username << endl;
	}

	virtual void viewDashBoard() = 0; //pure virtual function

	string getUserName();
	string getUserType();

};

#endif USER_H