#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H




using namespace std;

#include "User.h"
#include "Cart.h"


class Customer : public User{
	private:
		Cart cart;
	public:
		Customer();
		Customer(string, string);
		void viewDashBoard() override {
			cout << "Customer Dashboard for " << username << endl;
		};
		void login()override { 
		cout << "Customer login :" <<username<< endl;
		cout << "Enter 1 to browse Products..." << endl;
		cout << "Enter 2 to add products... " << endl;
		cout << "Enter 3 to view products..." << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			browseProducts();
			break;
		}
		case 2: {
			int id = rand(); string name, desc; float price; int qty;
			cin.ignore();
			cout << "Enter name of product..." << endl;
			getline(cin,name);
			cout << "Enter description of product..." << endl;
			getline(cin,desc);
			cout << "Enter price of product..." << endl;
			cin >> price;
			cout << "Enter qty of product available..." << endl;
			cin >> qty;

			Product p(id, name, desc, price, qty);
			addToCart(p);
			break;
		}
		case 3: {
			viewCart();
			break;
		}
		default: {
			cout << "Invalid Entry..." << endl;
			logout();
			break;
		}

		}
		
		}
		void logout()override { cout << "Customer logout :" <<username<< endl<<endl; }
		void browseProducts();
		void addToCart(Product);
		void viewCart();
		void checkOut();
};


#endif CUSTOMER_H
