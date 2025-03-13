#pragma once
struct CharStats
{
    int strength = 0; //determines basic attack
    int dexterity = 0; //determines basic defense
    int wit = 0; //determines special attack
    int wisdom = 0; //determines special defense

    int health = 10;
    int level = 0;
    float exp = 0;
    int gold = 0;

};

struct MonsterStats{
    int strength = 0; //determines basic attack
    int dexterity = 0; //determines basic defense
    int wit = 0; //determines special attack
    int wisdom = 0; //determines special defense

    int health = 0;
    float exp = 0;
    int gold = 0; //add gold to player gold stat/count
};
