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

int main(int argc, char* argv[])

{
    srand(time(NULL));

    Room room;
    room.Load("assets/level_1.map");


    /// Player Stats ///
    CharStats playerStats;

    //these stats are the same for everyone at the beginning
    playerStats.level = 1;
    playerStats.exp = 0;
    playerStats.gold = 0; 

    //class dependent stats
    char StatsInput;
    StatsInput = request_char("Select your class! F for fighter, C for cleric, W for wizard, R for rouge.");


    switch(StatsInput) {
        case 'F':
            playerStats.strength = 4;
            playerStats.dexterity = 2;
            playerStats.wit = 0;
            playerStats.wisdom = 1;
            playerStats.health = 12;

            printf("%c\n","you are a fighter! Stats:", "%c\n",
                    "strength: ", playerStats.strength, "%c\n",
                    "dexterity: ", playerStats.dexterity, "%c\n",
                    "wit: ", playerStats.wit, "%c\n",
                    "wisdom", playerStats.wisdom, "%c\n",
                    "health: ", playerStats.health, "%c\n",
                    "You are strong, but not vested in the arcane arts. Do not hesitate with your sword." "%c\n");
                    //class ability: add an extra die to your attack once per 3 rooms
            break;

        case 'C':
            playerStats.strength = 0;
            playerStats.dexterity = 2;
            playerStats.wit = 2;
            playerStats.wisdom = 4;
            playerStats.health = 14;

        printf("%c\n","you are a Cleric! Stats:", "%c\n",
                "strength: ", playerStats.strength, "%c\n",
                "dexterity: ", playerStats.dexterity, "%c\n",
                "wit: ", playerStats.wit, "%c\n",
                "wisdom", playerStats.wisdom, "%c\n",
                "health: ", playerStats.health, "%c\n",
                "You sheild yourself from the dark forces who hunt you. Banish them with your magic." "%c\n");
                //special ability: Fully heal yourself once per 3 rooms
            break;
        
        case 'W':
            playerStats.strength = 0;
            playerStats.dexterity = 3;
            playerStats.wit = 4;
            playerStats.wisdom = 2;
            playerStats.health = 10;

            printf("%c\n","you are a Wizard! Stats:", "%c\n",
                "strength: ", playerStats.strength, "%c\n",
                "dexterity: ", playerStats.dexterity, "%c\n",
                "wit: ", playerStats.wit, "%c\n",
                "wisdom", playerStats.wisdom, "%c\n",
                "health: ", playerStats.health, "%c\n",
                "You are vested in the arcane arts. Blast away your enemies with your spellbook before they can touch you." "%c\n");
                //special ability: you get slighltly more exp from each enemy that you kill
            break;
        
        case 'R':
            playerStats.strength = 3;
            playerStats.dexterity = 4;
            playerStats.wit = 2;
            playerStats.wisdom = 0;
            playerStats.health = 12;

            printf("%c\n","you are a Rouge! Stats:", "%c\n",
                "strength: ", playerStats.strength, "%c\n",
                "dexterity: ", playerStats.dexterity, "%c\n",
                "wit: ", playerStats.wit, "%c\n",
                "wisdom", playerStats.wisdom, "%c\n",
                "health: ", playerStats.health, "%c\n",
                "You become one with the shadows. Strike your enemies before they see you." "%c\n");
                //special ability: you get slightly more gold from each enemy that you kill
            break;
        
        default:
            playerStats.strength = 3;
            playerStats.dexterity = 4;
            playerStats.wit = 2;
            playerStats.wisdom = 0;
            playerStats.health = 12;

            printf("you are secret class X! It SUCKS. Stats:", "%c\n",
                "strength: ", playerStats.strength, "%c\n",
                "dexterity: ", playerStats.dexterity, "%c\n",
                "wit: ", playerStats.wit, "%c\n",
                "wisdom", playerStats.wisdom, "%c\n",
                "health: ", playerStats.health, "%c\n",
                "You're not good at much of anything. Good luck bozo!" "%c\n");
            break;
      }

// Dice Logic 

    while(true)
    {
        room.Update();
    }
  
    return 0;
}

int rollDice(int sides)

{
    return rand() % sides + 1;  
}

int getDiceSides(int level) 
{
    
    return 6 + level; 
}