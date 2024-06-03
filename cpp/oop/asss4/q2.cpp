#include <iostream>
#include <string>

using namespace std;

struct Product {
    string name;
    double price;
    int quantity;

    Product(const string& productName, double productPrice, int initialQuantity)
        : name(productName), price(productPrice), quantity(initialQuantity) {}
    Product(){
      name="";
      price=0;
      quantity=0;
    }
};

class InventoryManager {
private:
    static const int MAX_PRODUCTS = 100;
    Product products[MAX_PRODUCTS];
    int numProducts;

public:
    InventoryManager(){
      numProducts=0;
    }

    void addProduct(const string& productName, double productPrice, int initialQuantity) {
        if (numProducts < MAX_PRODUCTS) {
            products[numProducts++] = Product(productName, productPrice, initialQuantity);
            cout << "Product added successfully.\n";
        } else {
            cout << "Error: Maximum number of products reached.\n";
        }
    }

    void displayInventory() {
        cout << "Inventory:\n";
        for (int i = 0; i < numProducts; ++i) {
            cout << "Name: " << products[i].name << ", Price: Rs" << products[i].price
                 << ", Quantity: " << products[i].quantity << "\n";
        }
    }

    void checkStock(const string& productName) {
        for (int i = 0; i < numProducts; ++i) {
            if (products[i].name == productName) {
                cout << "Stock status for " << productName << ": " << products[i].quantity << " units\n";
                return;
            }
        }
        cout << "Product not found in the inventory.\n";
    }
};

int main() {
    InventoryManager inventory;

    inventory.addProduct("Product1", 100, 50);
    inventory.addProduct("Product2", 200, 30);

    inventory.displayInventory();

    inventory.checkStock("Product1");
    inventory.checkStock("Product3");

    return 0;
}
