#include <iostream>
#include <string>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;

std::string GetUserString(const std::string& prompt);

void AddMenuOption(ShoppingCart& userCart);
void RemoveMenuOption(ShoppingCart& userCart);
void ChangeMenuOption(ShoppingCart& userCart);
void DescriptionsMenuOption(ShoppingCart& userCart);
void CartMenuOption(ShoppingCart& userCart);
void OptionsMenuOption();
void QuitMenuOption();


int main() {
    std::string customerName = GetUserString("Enter Customer's Name: ");
    std::string todayDate = GetUserString("Enter Today's Date: ");
    ShoppingCart userCart(customerName, todayDate);

    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;
    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter option: ");

        if (userMenuChoice == "add") {
            AddMenuOption(userCart);
        }
        else if (userMenuChoice == "remove") {
            RemoveMenuOption(userCart);
        }
        else if (userMenuChoice == "change") {
            ChangeMenuOption(userCart);
        }
        else if (userMenuChoice == "descriptions") {
            DescriptionsMenuOption(userCart);
        }
        else if (userMenuChoice == "cart") {
            CartMenuOption(userCart);
        }
        else if (userMenuChoice == "options") {
            OptionsMenuOption();
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption();
            continueMenuLoop = false;
        }
        else {
            OptionsMenuOption();
        }
    }

    return 0;
}


std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
double GetUserDouble(const std::string& prompt) {
    double userAnswer = 0.0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}


void AddMenuOption (ShoppingCart& userCart) {
    std::string itemName = GetUserString("Enter the item name: ");
    std::string itemDescription = GetUserString("Enter the item description: ");
    double itemPrice = GetUserDouble("Enter the item price: ");
    int itemQuantity = GetUserInt("Enter the item quantity: ");

    ItemToPurchase item(itemName, itemDescription, itemPrice, itemQuantity);
    userCart.AddItem(item, itemName);

}

void RemoveMenuOption(ShoppingCart& userCart) {
    std::string nameOfItemToRemove = GetUserString("Enter name of the item to remove: ");
    userCart.RemoveItem(nameOfItemToRemove);
}

void ChangeMenuOption(ShoppingCart& userCart) {
    std::string nameOfItemToChange = GetUserString("Enter the item name: ");
    int newItemQuantity = GetUserInt("Enter the new quantity: ");
    ItemToPurchase newItem;
    newItem.SetName(nameOfItemToChange);
    newItem.SetQuantity(newItemQuantity);
    userCart.ModifyItem(newItem);

}

void DescriptionsMenuOption(ShoppingCart& userCart) {
    userCart.PrintDescriptions();
}

void CartMenuOption(ShoppingCart& userCart) {
    userCart.PrintTotal();
}

void OptionsMenuOption() {
    std::cout << "MENU" << std::endl
              << "add - Add item to cart" << std::endl
              << "remove - Remove item from cart" << std::endl
              << "change - Change item quantity" << std::endl
              << "descriptions - Print the items' descriptions" << std::endl
              << "cart - Print the shopping cart" << std::endl
              << "options - Print the options menu" << std::endl
              << "quit - Quit" << std::endl << std::endl;
}

void QuitMenuOption() {
    std::cout << "Goodbye." << std::endl;
}