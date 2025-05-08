#include "Admin.h"


Admin::Admin(){}
Admin::Admin(string user, string pass) :User(user, pass, "Admin") {

	
}



void Admin::manageProducts() {
	cout << "Admin is Managing Products..." << endl;
}

void Admin::manageUsers() {
	cout << "Admin is Managing Users..." << endl;
}

void Admin::viewOrders() {
	cout << "Admin is Viewing all orders..." << endl;
}