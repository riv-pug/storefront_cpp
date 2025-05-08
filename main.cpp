#include "Admin.h"
#include "Customer.h"
#include "Product.h"
#include "DataBaseManager.h"
#include "Order.h"

#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

// Binary Order File
const string ORDER_FILE = "orders.dat";
const string USER_FILE = "users.txt";

// User Record Structure
struct UserRecord {
    string userType;
    string username;
    string password;
};

// Function declarations
void trendingOptions();
vector<UserRecord> loadUsers();
void saveUser(UserRecord user);
void saveOrder(string username, vector<Product> purchasedItems, float total);


int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random for product ID generation

    cout << "Welcome to the Marketplace!" << endl;
    cout << "---------------------------" << endl;

    trendingOptions();  // Show trending products

    vector<UserRecord> users = loadUsers(); // Load existing users

    bool running = true;

    while (running) {
        string username, password, type;

        // Login Screen
        cout << "\n--- LOGIN ---\n";
        cout << "Enter account type (Admin or Customer): ";
        cin >> type;

        cin.ignore();
        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter password: ";
        getline(cin, password);

        // Check if user exists
        bool userFound = false;

        for (auto u : users) {
            if (u.userType == type && u.username == username && u.password == password) {
                userFound = true;
                cout << "Welcome back, " << username << "!\n";
                break;
            }
        }

        // If user does not exist → create + save
        if (!userFound) {
            cout << "New user. Creating account.\n";
            UserRecord newUser = { type, username, password };
            users.push_back(newUser);
            saveUser(newUser);
        }

        // ------------------ ADMIN ------------------
        if (type == "Admin" || type == "admin") {
            Admin admin(username, password);
           // admin.login();

            bool adminSession = true;
            while (adminSession) {
                cout << "\n[Admin Options]\n";
                cout << "1. Add Products\n";
                cout << "2. Manage Users\n";
                cout << "3. View Orders\n";
                cout << "4. Logout\n";
                cout << "Choose: ";
                int choice;
                cin >> choice;

                if (choice == 1) {
                   

                    DataBaseManager db("products.dat");
                    string pname, pdesc;
                    float pprice;
                    int pqty, pid = rand();

                    cin.ignore();
                    cout << "Enter product name: ";
                    getline(cin, pname);
                    cout << "Enter description: ";
                    getline(cin, pdesc);
                    cout << "Enter price: ";
                    cin >> pprice;
                    cout << "Enter quantity: ";
                    cin >> pqty;

                    Product prod(pid, pname, pdesc, pprice, pqty);
                    db.writeRecord(prod);
                }
                else if (choice == 2) {
                    admin.manageUsers();
                }
                else if (choice == 3) {
                    admin.viewOrders();
                  //  viewAllOrders();
                }
                else if (choice == 4) {
                    admin.logout();
                    adminSession = false;
                }
                else {
                    cout << "Invalid option.\n";
                }
            }
        }

        // ------------------ CUSTOMER ------------------
        else if (type == "Customer" || type == "customer") {
            Customer customer(username, password);
            customer.login();

            vector<Product> purchasedItems;
            bool shopping = true;

            while (shopping) {
                cout << "\n[Customer Options]\n";
                cout << "1. Browse Products\n";
                cout << "2. Add Product to Cart\n";
                cout << "3. View Cart\n";
                cout << "4. Checkout\n";
                cout << "5. Logout\n";
                cout << "Choose: ";
                int choice;
                cin >> choice;

                if (choice == 1) {
                    customer.browseProducts();
                }
                else if (choice == 2) {
                    int id = rand();
                    string pname, pdesc;
                    float pprice;
                    int pqty;

                    cin.ignore();
                    cout << "Enter product name: ";
                    getline(cin, pname);
                    cout << "Enter description: ";
                    getline(cin, pdesc);
                    cout << "Enter price: ";
                    cin >> pprice;
                    cout << "Enter quantity: ";
                    cin >> pqty;

                    Product p(id, pname, pdesc, pprice, pqty);
                    customer.addToCart(p);
                    purchasedItems.push_back(p);
                }
                else if (choice == 3) {
                    customer.viewCart();
                }
                else if (choice == 4) {
                    customer.viewCart();

                    float total = 0;
                    for (auto p : purchasedItems) {
                        total += p.getProductPrice();
                    }

                    cout << "Total: $" << total << endl;
                    cout << "Proceeding to checkout...\n";

                    customer.checkOut();

                    saveOrder(customer.getUserName(), purchasedItems, total);
                    shopping = false;
                }
                else if (choice == 5) {
                    customer.logout();
                    shopping = false;
                }
                else {
                    cout << "Invalid option.\n";
                }
            }
        }

        // Invalid User Type
        else {
            cout << "Invalid account type. Please try again.\n";
        }

        // Continue or exit
        char again;
        cout << "\nDo you want to login another user? (y/n): ";
        cin >> again;
        if (again != 'y' && again != 'Y') {
            running = false;
        }
    }

    cout << "Program ended.\n";
    return 0;
}

// Trending products
void trendingOptions() {
    cout << "\nCurrent Trending Marketplace Options:" << endl;
    cout << "* Coffee" << endl;
    cout << "* Eggs" << endl;
    cout << "* Fish" << endl;
    cout << "* Apples" << endl;
    cout << "* Orange Juice Concentrate" << endl << endl;
    cout << "Sign in to join the Marketplace!\n\n";
}

// Load users from file
vector<UserRecord> loadUsers() {
    vector<UserRecord> users;
    ifstream file(USER_FILE);
    if (!file.is_open()) return users;

    UserRecord user;
    while (file >> user.userType >> user.username >> user.password) {
        users.push_back(user);
    }

    file.close();
    return users;
}

// Save user to file
void saveUser(UserRecord user) {
    ofstream file(USER_FILE, ios::app);
    if (file.is_open()) {
        file << user.userType << " " << user.username << " " << user.password << endl;
        file.close();
    }
}

// Save order as binary
void saveOrder(string username, vector<Product> purchasedItems, float total) {
    ofstream outFile(ORDER_FILE, ios::binary | ios::app);
    if (!outFile.is_open()) {
        cout << "Unable to save order!" << endl;
        return;
    }

    // Save username
    int nameLength = username.size();
    outFile.write(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    outFile.write(username.c_str(), nameLength);

    // Save total
    outFile.write(reinterpret_cast<char*>(&total), sizeof(total));

    // Save product count
    int itemCount = purchasedItems.size();
    outFile.write(reinterpret_cast<char*>(&itemCount), sizeof(itemCount));

    // Save each product
    for (Product p : purchasedItems) {
        outFile.write(reinterpret_cast<char*>(&p), sizeof(Product));
    }

    outFile.close();
}

