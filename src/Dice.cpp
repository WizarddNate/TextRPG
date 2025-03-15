#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"

// Function to update the dice sides based on the player's level
int updateDiceSides(int level) {
    return 6 + (level - 1);  // Starting at 6 sides, increases by 1 with each level
}

// Function to roll the dice based on the current number of sides
int rollDice(int sides) {
    return rand() % sides + 1;  // Generates a number between 1 and 'sides'
}

// Function to level up the player
void levelUp(int& level, int& diceSides) {
    level++;  // Increment the player's level
    diceSides = updateDiceSides(level);  // Update dice sides based on the new level
    std::cout << "Congratulations! You've leveled up to level " << level << ". ";
    std::cout << "Your new dice has " << diceSides << " sides.\n";
}



