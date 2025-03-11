#pragma once
#include "Stats.hpp"
#include "Entity.hpp"

class Boss : public Entity
{
public:
    void Start();
    void Update();
    void Fight();

    /// Monster Stats ///
    CharStats bossStats;
    
    //bossStats.strength = 0; //random int + character level
    //bossStats.dexterity = 0; 
    //bossStats.wit = 0;
    //bosstats.wisdom = 0;
    //bossStats.health = 0; // + random int + character level
    
    //bossStats.exp = 0; //player recieves this upon death
    //bossStats.gold = 0;

private:
};