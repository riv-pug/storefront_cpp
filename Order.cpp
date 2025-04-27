#include "Order.h"


Order::Order() {}
void Order::displayOrderDetails() {

	cout << "Order ID: " << order_ID << " | Name: " << user_name << endl;
	for (int i = 0; i < purchased_Items.size(); i++) {
		purchased_Items[i].displayProductDetails();
	
	}
	cout << "Total: $" << total_Amount << endl;


}
