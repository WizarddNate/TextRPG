#include "Boss.hpp"
#include "Room.hpp"
#include "fogpi/fogpi.hpp"
void Boss::Start()
{
    m_character = 'B';

    bossStats.strength = 0; //random int + character level
    bossStats.dexterity = 0; 
    bossStats.wit = 0; 
    bossStats.wisdom = 0; 
    bossStats.health = 3; // + random int + character level
    
    bossStats.exp = 0; //player recieves this upon death
    bossStats.gold = 0;
}

void Boss::Update()
{

}

void Boss::Fight()
{
    //player chooses between regular and special attack
    char AttackInput;
    AttackInput = request_char("A great foe stands before you. Take your next Action Carefully. \n A for attack, S for speical attack, H to Heal");

    switch(AttackInput)
    {
        case 'A':
            //attack
        case 'S':
            //Special attack
        case 'H':
            //if healing items > 0:
            //heal
            //print "you heal for x. you have y potions remaining."
            //potions--
            //else print "You have no potions"
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
