#ifdef _WIN32
#include <windows.h>

#endif

#include <iostream>
#include <vector>
#include "fogpi/Math.hpp"
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "Dice.hpp"
#include "Entity.hpp"
#include "Room.hpp"
#include <cstdlib>
#include <ctime>
#include "Player.hpp"
#include "Dice.hpp"
#include "Dice.cpp"


int main(int argc, char* argv[])
{
    srand(time(NULL));

    Room room;
    room.Load("assets/level_1.map");


    while(true)
    {
        room.Update();
    }
  
    return 0;

    //Player Leveling system

    srand(time(0));  // Initialize random number generator

    int playerLevel = 1;  // Starting level
    int currentDiceSides = 6;  // Starting dice is a 6-sided die

    // Simulate a few level-ups and dice rolls
    for (int i = 0; i < 5; i++) {
        levelUp(playerLevel, currentDiceSides);  // Level up the player
        int rollDice = rollDice(currentDiceSides);  // Roll the dice
        std::cout << "You rolled a " << rollDice << " on your " << currentDiceSides << "-sided dice.\n\n";
    }

    return 0;
}