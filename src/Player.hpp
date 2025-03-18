#pragma once

#include <iostream>
#include "Entity.hpp"
#include "Stats.hpp"

class Player : public Entity
{
public:
    void Start();
    void Update();
    void StatsPick();
    int LevelUp();

    /// Player Stats ///
    CharStats playerStats;

private:
    int m_keyCount = 0;
    bool started = false;
};

