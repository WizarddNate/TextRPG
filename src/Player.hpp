#pragma once

#include "Entity.hpp"

class Player : public Entity
{
public:
    void Start();
    void Update();
    int health = 10;

private:
    int m_keyCount = 0;
    int m_goldCount =0;
};

