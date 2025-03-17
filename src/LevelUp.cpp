#include <iostream>
#include <string>
#include "Player.hpp"
#include "Stats.hpp"
#include "Dice.hpp"

class LevelUp{
private:
    std::string name;
    int level;
    int xp;
    int xpRequired;

public:
    // Constructor to initialize player with name and starting level
    LevelUp(std::string m_player) : name(m_player), level(1), xp(0), xpRequired(100) {}

    // Method to gain experience points
    void gainXP(int points) {
        xp += points;
        std::cout << name << " gained " << points << " XP!" << std::endl;
        checkLevelUp();
    }

    // Method to check if the player has leveled up
    void checkLevelUp() {
        while (xp >= xpRequired) {
            xp -= xpRequired;
            level++;
            xpRequired = static_cast<int>(xpRequired * 1.2);  // Increase the XP required for the next level
            std::cout << name << " leveled up! You are now level " << level << "." << std::endl;
        }
    }

    // Method to display player's stats
    void displayStats() const {
        std::cout << "Player: " << name << "\nLevel: " << level << "\nXP: " << xp << "/" << xpRequired << std::endl;
    }
};
