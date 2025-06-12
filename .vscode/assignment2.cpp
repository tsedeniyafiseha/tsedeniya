#include <iostream>
#include <iomanip>
using namespace std;

#define TAX_RATE 0.08

int main() {
    cout << "Welcome to the Product Sales and Inventory Analyzer!" << endl;
    cout << "This program helps analyze sales and inventory status for a store." << endl;
    cout << " C++ is a compiled language!\n" << endl;

    string productName;
    int productCategory;
    int initialInventory;
    float productPrice;
    int itemsSold;

    int newInventory;
    float totalSales;
    string inventoryStatus;

    const double TAX_RATE_CONST = 0.08;

    cout << "Enter product name: ";
    cin >> productName;
    cout << "Enter product category: ";
    cin >> productCategory;
    cout << "Enter initial inventory quantity: ";
    cin >> initialInventory;
    cout << "Enter product price per unit: ";
    cin >> productPrice;
    cout << "Enter number of items sold: ";
    cin >> itemsSold;

    newInventory = initialInventory;
    newInventory -= itemsSold;
    totalSales = itemsSold * productPrice;

    inventoryStatus = (newInventory < 10) ? "Low Inventory" : "Sufficient Inventory";

    auto totalSalesCopy = totalSales;
    decltype(initialInventory) backupInventory = initialInventory;

    if (productCategory < 1 || productCategory > 5) {
        cout << "Invalid product category!" << endl;
        return 1;
    }

    switch (productCategory) {
        case 1: cout << "Category 1: Electronics" << endl; break;
        case 2: cout << "Category 2: Groceries" << endl; break;
        case 3: cout << "Category 3: Clothing" << endl; break;
        case 4: cout << "Category 4: Stationery" << endl; break;
        case 5: cout << "Category 5: Miscellaneous" << endl; break;
    }

    cout << "\nPrinting receipt: \n";
    for (int i = 1; i <= itemsSold; i++) {
        cout << "Item " << i << ": $" << fixed << setprecision(2) << productPrice << endl;
    }

    cout << "\n--- Product Summary ---" << endl;
    cout << "Product Name: " << productName << endl;
    cout << "Product Category: " << productCategory << endl;
    cout << "Initial Inventory: " << initialInventory << endl;
    cout << "Price per Unit: $" << fixed << setprecision(2) << productPrice << endl;
    cout << "Items Sold: " << itemsSold << endl;
    cout << "New Inventory: " << newInventory << endl;
    cout << "Total Sales: $" << totalSales << endl;
    cout << "Inventory Status: " << inventoryStatus << endl;
    cout << "Backup Inventory: " << backupInventory << endl;
    cout << "Total Sales Copy: $" << totalSalesCopy << endl;
    cout << "Tax Rate (Preprocessor): " << TAX_RATE * 100 << "%" << endl;
    cout << "Tax Rate (Const): " << TAX_RATE_CONST * 100 << "%" << endl;

    return 0;
}
