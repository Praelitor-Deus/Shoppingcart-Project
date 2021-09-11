#include <iostream>
#include <string>
#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0.0;
    itemQuantity = 0;

    return;
}

ItemToPurchase::ItemToPurchase(string name, string description, double price, int quantity) {
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;

    return;
}

void ItemToPurchase::SetName(string name) {
    itemName = name;

    return;
}

string ItemToPurchase::GetName() const {
    return itemName;
}

void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;

    return;
}

string ItemToPurchase::GetDescription() const {
    return itemDescription;
}

void ItemToPurchase::SetPrice(double price) {
    itemPrice = price;

    return;
}

double ItemToPurchase::GetPrice() const {
    return itemPrice;
}

void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;

    return;
}

int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}
