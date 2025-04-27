#pragma once
#ifndef CART_H
#define CART_H

#include "Product.h"
#include <vector>
#include <iostream>
using namespace std;

class Cart
{
private:
	vector<Product> items;

public:
	Cart();
	void addProduct(Product p);

	void viewCart();

	float calculateTotal();

	void clearCart();



};

#endif CARD_H

