#include "Customer.h"


Customer::Customer() {}
Customer::Customer(string user, string pass):User(user, pass, "Customer") {}


void Customer::browseProducts() {

	cout << "Customer is Browsing products..." << endl;
}
void Customer::addToCart(Product p) {
	cart.addProduct(p);
}
void Customer::viewCart() {
	cart.viewCart();
}
void Customer::checkOut() {
	cout << "Customer Total amount: $" << cart.calculateTotal() << endl;
	cout << "Customer Proceeding to checout..." << endl;
	cart.clearCart();
}