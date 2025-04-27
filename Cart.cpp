#include "Cart.h"


Cart::Cart() {}
void Cart::addProduct(Product p) {
	items.push_back(p);
	cout << "Added item to cart: " << p.getProductName() << endl;
}

void Cart::viewCart() {

	cout << "---- Cart Item List ---- " << endl;
	for (int i = 0; i < items.size(); i++) {
		items[i].displayProductDetails();
	
	}

}

float Cart::calculateTotal() {
	float total = 0;
	for (int i = 0; i < items.size(); i++) {
		total = total +  items[i].getProductPrice();
	}

	return total;
}

void Cart::clearCart() {
	items.clear();
	cout << "Cart Cleard" << endl;
}