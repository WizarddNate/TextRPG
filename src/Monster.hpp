#pragma once

#include "Entity.hpp"

class Monster : public Entity
{
public:
    void Start();
    void Update();

    MonsterStats monsterStats;

private:
    
};