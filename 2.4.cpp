
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;
    double price;

    Product(int id = 0, string name = "", int quantity = 0, double price = 0.0)
        : id(id), name(name), quantity(quantity), price(price) {}

    void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Quantity: " << quantity
             << ", Price: Rs." << price << endl;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct() {
        int id, quantity;
        string name;
        double price;

        cout << "Enter product ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter product name: ";
        getline(cin, name);
        cout << "Enter quantity: ";
        cin >> quantity;
        cout << "Enter price: ";
        cin >> price;

        Product newProduct(id, name, quantity, price);
        products.push_back(newProduct);

        cout << "Product added successfully!" << endl;
    }
    void updateQuantity() {
        int id, newQuantity;
        cout << "Enter product ID to update: ";
        cin >> id;
        cout << "Enter new quantity: ";
        cin >> newQuantity;

        bool found = false;
        for (int i = 0; i < products.size(); i++) {
            if (products[i].id == id) {
                products[i].quantity = newQuantity;
                cout << "Product quantity updated successfully!" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Product with ID " << id << " not found!" << endl;
        }
    }

    double calculateTotalValue() {
        double total = 0.0;
        for (int i = 0; i < products.size(); i++) {
            total += products[i].quantity * products[i].price;
        }
        return total;
    }

    void displayInventory() {
        if (products.empty()) {
            cout << "Inventory is empty!" << endl;
            return;
        }

        cout << "\nInventory List:" << endl;
        for (int i = 0; i < products.size(); i++) {
            products[i].display();
        }
    }
    void buyProduct() {
        int id, buyQuantity;
        cout << "Enter product ID to buy: ";
        cin >> id;
        cout << "Enter quantity to buy: ";
        cin >> buyQuantity;

        bool found = false;
        for (int i = 0; i < products.size(); i++) {
            if (products[i].id == id) {
                found = true;
                if (products[i].quantity >= buyQuantity) {
                    products[i].quantity -= buyQuantity;
                    double totalCost = buyQuantity * products[i].price;
                    cout << "Purchase successful! Total cost: Rs." << totalCost << endl;
                } else {
                    cout << "Not enough stock! Only " << products[i].quantity << " available." << endl;
                }
                break;
            }
        }

        if (!found) {
            cout << "Product with ID " << id << " not found!" << endl;
        }
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add product\n";
        cout << "2. Update product quantity\n";
        cout << "3. Display inventory\n";
        cout << "4. Calculate total inventory value\n";
        cout << "5. Buy a product\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.addProduct();
                break;
            case 2:
                inventory.updateQuantity();
                break;
            case 3:
                inventory.displayInventory();
                break;
            case 4:
                cout << "Total value of inventory: Rs." << inventory.calculateTotalValue() << endl;
                break;
            case 5:
                inventory.buyProduct();
                break;
            case 6:
                cout << "Exiting the system" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != 6);

    cout<<"24CE027_Yash Desai\n";

    return 0;
}
