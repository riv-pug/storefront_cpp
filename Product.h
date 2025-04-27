#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;

class Product
{
private:
	int productID;
	string productName;
	string productDescription;
	float productPrice;
	int productQuantity;
public:

	Product();
	Product(int, string, string, float, int);

	void displayProductDetails();
	int getProductID();
	string getProductName();
	float getProductPrice();


};


#endif PRODUCT_H
