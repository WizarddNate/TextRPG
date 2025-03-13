/*#include <iostream>
#include <vector>
#include <string>

#include "Shop.hpp"
#include "Player.hpp"

using namespace std;

 

// Item structure

struct Item {

    string name;

    int price;

   

    Item(string n, int p) : name(n), price(p) {}

};

 

// Player class

class Player 
{

    public:

    string name;

    int gold;

    vector<Item> inventory;

 

    Player(string n, int m) : name(n), gold(G) {}

 

    // Method to buy an item in the shop

    void buyItem(Item& item) {

        if (gold >= item.price) {

            gold -= item.price;

            inventory.push_back(item);

            cout << "You bought " << item.name << " for " << item.price << " gold!" << endl;

        } else {

            cout << "Sorry! You don't have enough gold to buy " << item.name << "." << endl;

        }

    }

 

};

 

// Class for the Shop

class Shop {

public:

    vector<Item> shopInventory;



  // Adding the items to the shop and the Gold prices

    Shop() {

        // Healing and Support Items

        shopInventory.push_back(Item("Potion", 2));

        shopInventory.push_back(Item("Ether", 3));

        // Warrior Class Weapons and Armor

        shopInventory.push_back(Item("One-Handed Sword", 10));

        shopInventory.push_back(Item ("Shield", 10));

        shopInventory.push_back(Item("Steel Armor", 20));
        
        // Rogue Class Weapons and Armor

        shopInventory.push_back(Item("Dual Daggers", 10));

        shopInventory.push_back(Item("Longbow", 15));

        shopInventory.push_back(Item ("Leather Armor", 20));

        //Mage Class Weapons and Robes

        shopInventory.push_back(Item("Dual Wands ", 10 ));

        shopInventory.push_back(Item("Staff", 15));

        shopInventory.push_back(Item("Silk Robe", 20));


    }

 

    // Method to display the shop items

    void displayItems() {

        cout << "Welcome to the shop! Here's what we have for sale:" << endl;

        for (size_t i = 0; i < shopInventory.size(); ++i) {

            cout << i + 1 << ". " << shopInventory[i].name << " - " << itemsForSale[i].price << " gold" << endl;

        }

    }

};

 

// Main function to drive the shop interaction

int main() {

    // Create a player

    Player player("Hero", 150);

    // Create the shop

    Shop shop;

 

    int choice;

    bool running = true;

    // While the shop is open for the player in-game

    while (running) {

        cout << "\nWhat would you like to do?" << endl;

        cout << "1. Visit shop" << endl;

        cout << "2. Show inventory" << endl;

        cout << "3. Exit game" << endl;

        cin >> choice;

 

        switch (choice) {

        case 1:

            // Player visits shop

            shop.displayItems();

            cout << "Enter the number of the item you want to buy (0 to cancel): ";

            int itemChoice;

            cin >> itemChoice;

 

            if (itemChoice > 0 && itemChoice <= shop.itemsForSale.size()) {

                // Player buys the selected item

                player.buyItem(shop.itemsForSale[itemChoice - 1]);

            } else if (itemChoice == 0) {

                cout << "You left the shop." << endl;

            } else {

                cout << "Invalid choice." << endl;

            }

            break;

 

        case 2:

            // Show inventory

            player.showInventory();

            break;

 

        case 3:

            // Exit game

            running = false;

            cout << "Exiting game. Goodbye!" << endl;

            break;

 

        default:

            cout << "Invalid option!" << endl;

        }

    }

 

    return 0;

}*/
