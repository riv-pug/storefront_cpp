#pragma once
#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>

#include <string>
#include "Product.h"

using namespace std;



class Order
{
	private:
		int order_ID;
		string user_name;
		vector<Product> purchased_Items;
		float total_Amount;
		string order_Date;
	
	public:
		Order();
		void displayOrderDetails();




};

#endif ORDER_H