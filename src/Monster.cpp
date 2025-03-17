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

int rollD6() 
{
    return rand() % 6 + 1;
}

int rollD2()
{
    return rand() % 2 + 1;
}

void Monster::Update()
{
    
}

void Monster::GenerateStats()
{
        /// Player Stats ///
        const CharStats& playerStats = ((Player&)(room->GetPlayer())).playerStats;

        die.sides = 6;

        monsterStats.strength = 1 + (playerStats.level * 2) + rollD6(); //+ roll.RollDice(); // + random int 
        monsterStats.dexterity = 2 + (playerStats.level * 2) + rollD6(); 
        monsterStats.wit = 0 + (playerStats.level * 2) + rollD6(); 
        monsterStats.wisdom = 1 + (playerStats.level * 2) + rollD6(); 
        monsterStats.health = 2 + (playerStats.level * 2) + rollD6(); // + random int 
    
        monsterStats.exp = 2 + (playerStats.level * 3) + rollD6(); //player recieves this upon death
        monsterStats.gold = 1 + (playerStats.level * 3) + rollD6();
}

void Monster::Fight()
{
    /// Player Stats ///
    const CharStats& playerStats = ((Player&)(room->GetPlayer())).playerStats;

    //printf(playerStats.level);
    //printf(monsterStats.health);

    //player chooses between regular and special attack
    char AttackInput;
    AttackInput = request_char("A great foe stands before you. Take your next Action Carefully. \n A for attack, S for speical attack");

    switch(AttackInput)
    {
        case 'A':
            monsterStats.health = monsterStats.health - ((monsterStats.dexterity + rollD6()) - (playerStats.strength + rollD6()));
            printf("You do %i points in strength damage, the monster has %i hp remaining \n", monsterStats.exp, monsterStats.health);
        case 'S':
            //monsterStats.health = monsterStats.health - ((monsterStats.wisdom + rollD6()) - (playerStats.wit + rollD6()));
            printf("You do %i points in magic damage with your wit, the monster has %i hp remaining \n", monsterStats.exp, monsterStats.health);
        default:
            printf("You choke from your nerves and do nothing \n");
    }

    //check if monster died from that attack
    if (monsterStats.health <= 0)
    {
        //call win function
    }
    else //monsters turn to attack
    {
        int flipCoin = rollD2();
        if (flipCoin = 1)
        {
            //monster makes a normal attack
            //playerStats.health = playerStats.health - ((playerStats.dexterity + rollD6()) - (monsterStats.strength + rollD6()));
            printf("The monster hits you for %i points in strength damage, you have %i hp remaining \n", monsterStats.strength, monsterStats.health);
        }
        else
        {
            //monster makes a special attack
            //playerStats.health = playerStats.health - ((playerStats.wisdom + rollD6()) - (monsterStats.wit + rollD6()));
            printf("The monster hits you for  %i points in magic damage with its wit, you have %i hp remaining \n", monsterStats.wit, monsterStats.health);
        }
    }

    //check if player is dead
    //if (playerStats.health <= 0)
    {
        //call death function
    }
}