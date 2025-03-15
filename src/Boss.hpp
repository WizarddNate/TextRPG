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
    MonsterStats bossStats;

private:
    bool statsGenerated = false;
    void GenerateStats();
};