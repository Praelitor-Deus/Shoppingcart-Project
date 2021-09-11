#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include <iomanip>
#include <string>
using namespace std;

class ItemToPurchase {
public:
    ItemToPurchase();
    ItemToPurchase(string name, string description, double price = 0, int quantity = 0);
    void SetName(string description);
    string GetName() const;
    void SetDescription(string name);
    string GetDescription() const;
    void SetPrice(double price);
    double GetPrice() const;
    void SetQuantity(int quantity);
    int GetQuantity() const;

private:
    string itemName;
    string itemDescription;
    double itemPrice;
    int itemQuantity;
};

#endif