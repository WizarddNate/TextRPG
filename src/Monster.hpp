#pragma once

#include "Entity.hpp"
#include "Dice.hpp"
#include "Player.hpp"
#include "Room.hpp"

class Monster : public Entity
{
public:
    void Start();
    void Update();
    void Fight();

    MonsterStats monsterStats;
    Die die;
    RollStats roll;

private:
    bool statsGenerated = false;
    void GenerateStats();
    //int rollD6();
    //int rollD2();
};