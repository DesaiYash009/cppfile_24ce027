#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Structure to represent an item
struct Product {
    char name[50];
    int quantity;
    float price;
};

// Function to add a new product to the inventory file
void addProduct(const char* filename) {
    Product product;

    cout << "\nEnter Product Name: ";
    cin.ignore();  // Clear input buffer
    cin.getline(product.name, 50);

    cout << "Enter Quantity: ";
    cin >> product.quantity;

    cout << "Enter Price: ";
    cin >> product.price;

    ofstream file(filename, ios::app | ios::binary);  // Append in binary mode
    if (!file) {
        cerr << "Error: Could not open file to add product.\n";
        return;
    }

    file.write(reinterpret_cast<char*>(&product), sizeof(Product));
    file.close();

    cout << "Product added successfully.\n";
}

// Function to view all products from the inventory file
void viewInventory(const char* filename) {
    ifstream file(filename, ios::in | ios::binary);
    if (!file) {
        cerr << "Error: Could not open inventory file.\n";
        return;
    }

    Product product;
    cout << "\n--- Inventory List ---\n";
    while (file.read(reinterpret_cast<char*>(&product), sizeof(Product))) {
        cout << "Name     : " << product.name << endl;
        cout << "Quantity : " << product.quantity << endl;
        cout << "Price    : " << product.price <<" rupees"<< endl;
        cout << "----------------------\n";
    }

    file.close();
}

// Function to search for a product by name
void searchProduct(const char* filename) {
    char searchName[50];
    cout << "\nEnter Product Name to Search: ";
    cin.ignore();
    cin.getline(searchName, 50);

    ifstream file(filename, ios::in | ios::binary);
    if (!file) {
        cerr << "Error: Could not open file for searching.\n";
        return;
    }

    Product product;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&product), sizeof(Product))) {
        if (strcmp(product.name, searchName) == 0) {
            cout << "\nProduct Found:\n";
            cout << "Name     : " << product.name << endl;
            cout << "Quantity : " << product.quantity << endl;
            cout << "Price    : rupees" << product.price << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found in inventory.\n";
    }

    file.close();
}

int main() {
    const char* filename = "inventory.dat";
    int choice;

    do {
        cout << "\n=== Inventory Management System ===\n";
        cout << "1. Add Product\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(filename); break;
            case 2: viewInventory(filename); break;
            case 3: searchProduct(filename); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    cout<<endl<<"24CE027_yash Desai"<<endl;

    return 0;
}
