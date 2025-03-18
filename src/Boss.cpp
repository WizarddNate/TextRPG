#include "Boss.hpp"
#include "Room.hpp"
#include "fogpi/fogpi.hpp"
#include "Player.hpp"

void Boss::Start()
{
    m_character = 'B';

    if (statsGenerated == false)
    {
        statsGenerated = true;
        GenerateStats();
    }
}

int rollDD6() 
{
    return rand() % 6 + 1;
}

int rollDD2()
{
    return rand() % 2 + 1;
}

void Boss::GenerateStats()
{
    /// Player Stats ///
    const CharStats& playerStats = ((Player&)(room->GetPlayer())).playerStats;

    bossStats.strength = 3+ (playerStats.level * 2) + rollDD6(); //random int + character level
    bossStats.dexterity = 2+ (playerStats.level * 2) + rollDD6(); 
    bossStats.wit = 2+ (playerStats.level * 2) + rollDD6(); 
    bossStats.wisdom = 1+ (playerStats.level * 2) + rollDD6(); 
    bossStats.health = 3+ (playerStats.level * 2) + rollDD6(); // + random int + character level
    
    bossStats.exp = 5+ (playerStats.level * 2) + rollDD6(); //player recieves this upon death
    bossStats.gold = 7+ (playerStats.level * 2) + rollDD6();
}

void Boss::Fight()
{
    /// Player Stats ///
    CharStats& playerStats = ((Player&)(room->GetPlayer())).playerStats;

    if (bossStats.health <= 0)
    {
        printf("You have defeted the Boss of the monsters\n");
        return;
    }

    //player chooses between regular and special attack
    char AttackInput;
    AttackInput = request_char("A monsterous Boss stands before you. Take your next Action Carefully. \n A for attack, S for speical attack, H to Heal");

    switch(AttackInput)
    {
        case 'A':
            //attack
            bossStats.health = bossStats.health - abs((bossStats.dexterity + rollDD6()) - (playerStats.strength + rollDD6()));
            printf("You do %i points in strength damage, the Boss has %i hp remaining \n", playerStats.strength, bossStats.health);
            break;
        case 'S':
            //Special attack
            bossStats.health = bossStats.health - abs((bossStats.wisdom + rollDD6()) - (playerStats.wit + rollDD6()));
            printf("You do %i points in magic damage with your wit, the Boss has %i hp remaining \n", playerStats.wit, bossStats.health);
            break;
        default:
            printf("You are frozen with fear and do nothing\n");
    }
    //check if monster died from that attack
    if (bossStats.health <= 0)
    {
        playerStats.exp = playerStats.exp + bossStats.exp;
        playerStats.gold = playerStats.gold + bossStats.gold;
        playerStats.health = playerStats.health + ( 2 + rollDD6());
    
        room->monsterCount--;
        //room->ClearLocation(tryPos);
        // m_monsters.erace(m_monsters.begin() + i) <-
        //remove monster from array: Monster.remove/erase(monster.beginning + index)
        printf("*** You have defeted the Boss monster!*** \n you got %i gold pieces, %i exp, and your health has been restored to %i points.\n", bossStats.gold, bossStats.exp, playerStats.health);
    }
    else //monsters turn to attack
    {
        int flipCoin = rollDD2();
        if (flipCoin = 1)
        {
            //monster makes a normal attack
            playerStats.health = playerStats.health - abs((playerStats.dexterity + rollDD6()) - (bossStats.strength + rollDD6()));
            printf("The Boss hits you for %i points in strength damage, you have %i hp remaining \n", bossStats.strength, playerStats.health);
        }
        else
        {
            //monster makes a special attack
            playerStats.health = playerStats.health - abs((playerStats.wisdom + rollDD6()) - (bossStats.wit + rollDD6()));
            printf("The Boss hits you for %i points in magic damage with its wit, you have %i hp remaining \n", bossStats.wit, playerStats.health);
        }
    }

    //check if player is dead
    if (playerStats.health <= 0)
    {
        //handle death
        printf("*** You have died. ***\n Final Level: %i\n Gold Amount: %i\n", playerStats.level, playerStats.gold);
        exit(0);
    }

    printf("You take a step back and heal\n");


    

    //monster health = monster health - (player attack (special or regular) - monster defense (special or regular))

    // if monster health > 0, call collect function (?) break

    //else, monster chooses between special and basic attack

    //player health = player health - (monster attack (special or regular) - player defense (special or regular))
}
