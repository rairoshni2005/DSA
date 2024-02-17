#include <iostream>
#include <string>

using namespace std;

const int MAX_PRODUCTS = 110; // Increased maximum products to accommodate bakery items

struct Product {
    string name;
    int quantity;
};

class InventoryManagementSystem {
private:
    Product inventory[MAX_PRODUCTS];
    int numProducts;

public:
    InventoryManagementSystem() : numProducts(0) {}

    void addProduct(string name, int quantity) {
        if (numProducts < MAX_PRODUCTS) {
            inventory[numProducts].name = name;
            inventory[numProducts].quantity = quantity;
            numProducts++;
            cout << "Product added: " << name << ", Quantity: " << quantity << endl;
        } else {
            cout << "Inventory is full. Cannot add more products." << endl;
        }
    }

    void updateProductQuantity(string name, int quantity) {
        for (int i = 0; i < numProducts; ++i) {
            if (inventory[i].name == name) {
                inventory[i].quantity = quantity;
                cout << "Quantity updated for product " << name << ": " << quantity << endl;
                return;
            }
        }
        cout << "Product not found in inventory: " << name << endl;
    }

    void displayInventory() {
        cout << "Current Inventory:" << endl;
        for (int i = 0; i < numProducts; ++i) {
            cout << "Product: " << inventory[i].name << ", Quantity: " << inventory[i].quantity << endl;
        }
    }

    void checkLowStock(int threshold) {
        cout << "Low Stock Alert:" << endl;
        for (int i = 0; i < numProducts; ++i) {
            if (inventory[i].quantity < threshold) {
                cout << "Low stock for product " << inventory[i].name << ": " << inventory[i].quantity << " units" << endl;
            }
        }
    }
};

int main() {
    InventoryManagementSystem inventorySystem;
    int choice;
    string name;
    int quantity;

    do {
        cout << "\nMenu:\n1. Add Product\n2. Update Product Quantity\n3. Display Inventory\n4. Check Low Stock\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter product quantity: ";
                cin >> quantity;
                inventorySystem.addProduct(name, quantity);
                break;
            case 2:
                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter updated quantity: ";
                cin >> quantity;
                inventorySystem.updateProductQuantity(name, quantity);
                break;
            case 3:
                inventorySystem.displayInventory();
                break;
            case 4:
                int threshold;
                cout << "Enter threshold for low stock: ";
                cin >> threshold;
                inventorySystem.checkLowStock(threshold);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}