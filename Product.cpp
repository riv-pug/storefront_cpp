#include "Product.h"



Product::Product() {}
Product::Product(int id, string name, string des, float p, int q) {
	productID = id;
	productName = name;
	productDescription = des;
	productPrice = p;
	productQuantity = q;

}

void Product::displayProductDetails() {
	cout << productID << " - " << productName << " ($" << productPrice << ") - Quantity Available: " << productQuantity << endl;

}
int Product::getProductID() { return productID; }
string Product::getProductName() { return productName; }
float Product::getProductPrice() { return productPrice; }
