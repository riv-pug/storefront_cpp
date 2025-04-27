#include "Admin.h"
#include "Customer.h"
#include "Product.h"
#include "DataBaseManager.h"



using namespace std;


int main() {

	Admin admin("admin", "1234");
	Customer customer("John_Doe", "9876");

	Product eggs(1, "Eggs", "27,000 dozen eggs", 50000, 1);
	Product coffee(2, "Coffee Beans", "30000 pounds of roasted coffee beans", 65000, 5);

	admin.login();
	admin.viewDashBoard();
	admin.manageProducts();
	admin.logout();


	customer.login();
	customer.viewDashBoard();
	customer.addToCart(eggs);
	customer.addToCart(coffee);
	customer.viewCart();
	customer.logout();


	DataBaseManager db("products.dat");
	db.writeRecord(eggs);
	db.writeRecord(coffee);
	db.readRecord();


	return 0;
}