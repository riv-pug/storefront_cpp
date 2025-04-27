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
		}
		void browseProducts();
		void addToCart(Product);
		void viewCart();
		void checkOut();
};


#endif CUSTOMER_H
