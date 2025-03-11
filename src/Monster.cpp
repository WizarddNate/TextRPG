#include "Monster.hpp"
#include "Room.hpp"

void Monster::Start()
{
    m_character = 'M';

    /// Monster Stats ///
    CharStats monsterStats;
    
    monsterStats.strength = 0; //random int + character level
    monsterStats.dexterity = 0; 
    monsterStats.wit = 0; 
    monsterStats.wisdom = 0; 
    monsterStats.health = 2; // + random int + character level

    monsterStats.exp = 0; //player recieves this upon death
    monsterStats.gold = 0;
}

void Monster::Update()
{

}