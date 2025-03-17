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
#include "LevelUp.cpp"
#include "Dice.cpp"


int main(int argc, char* argv[])
{
    srand(time(NULL));

    Room room;
    room.Load("assets/level_boss.map");


    while(true)
    {
        room.Update();
    }
  
    return 0;

    //Player Level

    srand(time(0));  // Seed for random number generation

    LevelingUp player(1);

    cout << "Player is at level " << player.level << " with a " << player.dice_sides << "-sided dice." << endl;

    // Simulate leveling up and rolling dice
    for (int i = 0; i < 10; i++) {
        player.levelUp();  // Player levels up
        cout << "Rolling the dice... You rolled a " << player.rollDice() << "!" << endl;
        cout << endl;
    }

    return 0;
}
