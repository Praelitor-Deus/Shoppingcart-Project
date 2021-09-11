#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
#include <iomanip>
#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
public:
    ShoppingCart();
    ShoppingCart(string customerName, string currentDate);
    void AddItem(ItemToPurchase item, string itemName);
    void RemoveItem(string itemName);
    void ModifyItem(ItemToPurchase item);
    int GetNumItemsInCart() const;
    void PrintTotal() const;
    void PrintDescriptions() const;

private:
    string customerName;
    string currentDate;
    vector<ItemToPurchase> cartItems;
};

#endif