#pragma once

#include <iostream>
#include "Entity.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Room.hpp"

class Boss: public Entity
{
public:
    void Start();
    //void Update(); 
    void Fight();

    BossStats bossStats;
    Die die;
    RollStats roll;

private:
    bool statsGenerated = false;
    void GenerateStats();
};