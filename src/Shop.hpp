#include <iostream>
#include "Room.hpp"

#include <vector>
#include <string>

#include "Stats.hpp"
#include "Player.hpp"


struct Items {
    std::string name;
    std::string description;
    int cost;
    int effect;
    int buyItem;
    int itemChoice;
    int price;
};

//Setting up inventory/shop

std::vector<Items> shopInventory = {

    //Healing and Support
    {"Potion", "Restores X amount of HP", },
    {"Ether", "Restores X amount of MP", },

    //Warrior Weapons and Armor
    {"One-Handed Sword", "Deals X amount of damage", },
    {"Shield", "Reduces damage by X ", },
    {"Steel Armor", "Grants extra X percent of defense but slower movement. X percent chance to completely nullify enemy physical attack", },

    //Rogue Weapons and Armor

    {"Daggers 2x","Deals X damage per regular hit. Double damage per hit if successful sneak roll", },
    {"Longbow", "Deals X damage. Can attack from two squares away from enemy. X percent chance to perform critical hit"},
    {"Leather Armor","Grants extra X defense. X percent chance to dodge enemy attack", },

    //Mage Weapons and Robes

    {"Dual Wands", "Deals X Magic Damage damage per hit. Can attack from one square away from enemy", },
    {"Staff" "Deals X magic damage. Can attack from two squares away from enemy", },
    {"Silk Robe", "Grants extra X defense. X percent chance to absorb magical attacks to restore X percent of total mana", }
    
};