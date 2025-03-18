#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.hpp"
#include "Stats.hpp"

using namespace std;

class LevelingUp
{
public:
    int level;  // Player's level
    int dice_sides;  // Number of sides on the dice

    LevelingUp(int lvl) : level(lvl), dice_sides(6) {  // Start with a 6-sided die
        updateDiceSides();
    }

    // Method to update the number of dice sides when the player levels up
    void levelUp() {
        level++;
        updateDiceSides();
        cout << "Level up! Player is now level " << level << ". ";
        cout << "Dice has " << dice_sides << " sides." << endl;
    }

    // Method to adjust the dice sides based on the level
     void updateDiceSides() {
        // every 1 levels, the dice gains 2 more sides
        if (level >= 1) {
            dice_sides = 6 + (level / 1) * 2;
        }
    }

    // Method to roll the dice
    int rollDice() {
        return rand() % dice_sides + 1;
    }
};