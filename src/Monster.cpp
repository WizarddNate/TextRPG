#include "Monster.hpp"
#include "Room.hpp"
#include "Player.hpp"


void Monster::Start()
{
    m_character = 'M';

    if (statsGenerated == false)
    {
        statsGenerated = true;
        GenerateStats();
    }
}

void Monster::Update()
{
    
}

void Monster::GenerateStats()
{
        /// Player Stats ///
        CharStats playerStats;

        /// Monster Stats ///
        CharStats monsterStats;

        die.sides = 6;

        //monsterStats.strength = 1 + (playerStats.level * 2) + (RollDice(1)); //+ roll.RollDice(); // + random int 
        monsterStats.dexterity = 2 + (playerStats.level * 2); 
        monsterStats.wit = 0 + (playerStats.level * 2); 
        monsterStats.wisdom = 1 + (playerStats.level * 2); 
        monsterStats.health = 2 + (playerStats.level * 2); // + random int 
    
        monsterStats.exp = 2 + (playerStats.level * 3); //player recieves this upon death
        monsterStats.gold = 1 + (playerStats.level * 3);
}

void Monster::Fight()
{
    //player chooses between regular and special attack
    char AttackInput;
    AttackInput = request_char("A great foe stands before you. Take your next Action Carefully. \n A for attack, S for speical attack");

    switch(AttackInput)
    {
        case 'A':
            //monsterStats.health = monsterStats.health - ((monsterStats.dexterity) - (playerStats.strength));
        case 'S':
            //Special attack
        default:
            printf("You choke from your nerves and do nothing");
    }

    //check if monster died from that attack
    // if (monsterStats.health <= 0)
    // {
    //     //call win function
    // }
    // else //monsters turn to attack
    // {

    // }


    

    //monster health = monster health - (player attack (special or regular) - monster defense (special or regular))

    // if monster health > 0, call collect function (?) break

    //else, monster chooses between special and basic attack

    //player health = player health - (monster attack (special or regular) - player defense (special or regular))
}