#include <QString>
#include <iostream>
#include "product.h"
#include "vendor.h"
#include <limits>

using namespace std;

template <typename T>
T promptInput(const string& message)
{
    T input;
    bool validInput = false;
    while (!validInput) {
        cout << message;
        if (!(cin >> input)) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume the remaining input
        } else {
            validInput = true;
        }
    }
    return input;
}

string promptStringInput(const string& message)
{
    string input;
    cout << message;
    getline(cin, input);
    return input;
}

int main()
{
    string supplierName, supplierAddress, isManufacturerString;
    bool isManufacturer = false;
    string productName;
    double productPrice;

    // Get input for product name and price
    productName = promptStringInput("Enter product name: ");

    while (true) {
        try {
            productPrice = promptInput<double>("Enter product price: ");
            break;
        } catch (const exception& e) {
            cout << "Invalid input. Please try again." << endl;
        }
    }

    // Get input for supplier details
    cin.ignore(); // Consume the newline character
    supplierName = promptStringInput("Enter supplier name: ");
    supplierAddress = promptStringInput("Enter supplier address: ");

    while (true) {
        isManufacturerString = promptStringInput("Is supplier manufacturer? (Yes/No): ");
        if (isManufacturerString == "Yes") {
            isManufacturer = true;
            break;
        } else if (isManufacturerString == "No") {
            break;
        } else {
            cout << "Invalid input. Please enter 'Yes' or 'No'." << endl;
        }
    }

    // Create a Product object with the given name and price
    Product product(productName.c_str(), productPrice);

    // Set the supplier of the product to the vendor object
    product.setSupplier(supplierName.c_str(), supplierAddress.c_str(), isManufacturer);

    // Display the product details without supplier details
    cout << "Product details without supplier: " << endl << product.toString(false).toStdString() << endl;

    // Display the product details with supplier details
    cout << "Product details with supplier: " << endl << product.toString(true).toStdString() << endl;

    return 0;
}
