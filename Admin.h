#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>

using namespace std;

#include "User.h"

class Admin : public User
{
public:
	Admin();
	Admin(string, string);
	void login()override { cout << "Admin login : " <<username<< endl; }
	void logout()override { cout << "Admin logout : " <<username<< endl<<endl; }
	void viewDashBoard()override {
		cout << "Admin Dashboard for " << username << endl;
	}

	void manageProducts();

	void manageUsers();

	void viewOrders();
};

#endif ADMIN_H