#include "Admin.h"


Admin::Admin(){}
Admin::Admin(string user, string pass) :User(user, pass, "Admin") {

	
}



void Admin::manageProducts() {
	cout << "Managing Products..." << endl;
}

void Admin::manageUsers() {
	cout << "Managing Users..." << endl;
}

void Admin::viewOrders() {
	cout << "Viewing all orders..." << endl;
}