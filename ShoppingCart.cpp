#include <iostream>
#include <iomanip>
#include <string>
#include "ShoppingCart.h"
using namespace std;

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";

    return;
}

ShoppingCart::ShoppingCart(string customerName, string currentDate) {
    this->customerName = customerName;
    this->currentDate = currentDate;

    return;
}

void ShoppingCart::AddItem(ItemToPurchase item, string itemName) {
    for (unsigned int i = 0; i < cartItems.size(); ++i) {
        if ((cartItems.at(i).GetName() == itemName)) {
            cout << "Item is already found in the cart. It will not be added." << endl << endl;
            return;
        }
    }

    cartItems.push_back(item);

    return;
}

void ShoppingCart::RemoveItem(string itemName) {
    bool found = false;

    for (unsigned int i = 0; i < cartItems.size(); ++i) {
        if ((cartItems.at(i).GetName() == itemName) && (!found)) {
            cartItems.erase(cartItems.begin() + i);
            found = true;
        }
    }

    if (!found) {
        cout << "Item not found in cart. It will not be removed." << endl;
    }

    return;
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
    bool found = false;

    for (unsigned int i = 0; i < cartItems.size(); ++i) {
        string name = cartItems.at(i).GetName();
        string description = cartItems.at(i).GetDescription();
        double price = cartItems.at(i).GetPrice();
        int quantity = cartItems.at(i).GetQuantity();

        if ((!found) && (name == item.GetName())) {
            if ((description != "none") && (price != 0) && (quantity != 0)) {
                item.SetName(name);
                item.SetDescription(description);
                item.SetPrice(price);

                cartItems.at(i) = item;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "Item not found in cart. It will not be modified." << endl;
    }

    return;
}

int ShoppingCart::GetNumItemsInCart() const {
    int sum = 0;

    for (unsigned int i = 0; i < cartItems.size(); ++i) {
        sum += cartItems.at(i).GetQuantity();
    }

    return sum;
}


void ShoppingCart::PrintTotal() const {
    string name;
    double price;
    int quantity;
    double totalPrice;
    double total = 0;

    cout << customerName << "'s Shopping Cart - " << currentDate << endl;


    if (cartItems.size() == 0) {
        cout << "Shopping cart is empty." << endl;

    } else {
        cout << "Number of Items: " << GetNumItemsInCart() << endl;
        for (unsigned int i = 0; i < cartItems.size(); ++i) {
            name = cartItems.at(i).GetName();
            price = cartItems.at(i).GetPrice();
            quantity = cartItems.at(i).GetQuantity();
            totalPrice = price * quantity;

            cout << fixed << setprecision(2) << name << " " << quantity << " @ $" << price << " = $" << totalPrice << endl;

            total += totalPrice;

        }
        cout << endl << "Total: $" << total << endl;
    }



    return;
}

void ShoppingCart::PrintDescriptions() const {
    cout << customerName << "'s Shopping Cart - " << currentDate << endl;
    if(GetNumItemsInCart() == 0){
        cout << "Shopping cart is empty." << endl;
        return;
    }

    cout << "Item Descriptions" << endl;

    for (unsigned int i = 0; i < cartItems.size(); ++i) {
        cout << cartItems.at(i).GetName() << ": " << cartItems.at(i).GetDescription() << endl;
    }

    return;
}