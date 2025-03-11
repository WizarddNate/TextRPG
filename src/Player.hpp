#pragma once

#include <iostream>
#include "Entity.hpp"
#include "Stats.hpp"

class Player : public Entity
{
public:
    void Start();
    void Update();
    int health = 10;

    /// Player Stats ///
    CharStats playerStats;

    //these stats are the same for everyone at the beginning
    // playerStats.level = 0;
    // playerStats.exp = 0;
    // playerStats.gold = 0; 

    // playerStats.strength = 0;
    // playerStats.dexterity = 0;
    // playerStats.wit = 0;
    // playerStats.wisdom = 0;
    // playerStats.health = 0;


private:
    int m_keyCount = 0;
};